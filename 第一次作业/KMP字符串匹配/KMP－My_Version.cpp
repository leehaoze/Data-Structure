//NCC_31060 Majestic
#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

#define input(a) scanf("%d",&a);
#define print_one_blank printf(" ");

#define N 501

void cal_next(const char *str, int *next, int len) {
    int i, j;

    next[0] = -1;
    for (i = 1; i < len; i++) {
        j = next[i - 1];
        while (str[j + 1] != str[i] && (j >= 0)) {
            j = next[j];
        }
        if (str[i] == str[j + 1]) {
            next[i] = j + 1;
        } else {
            next[i] = -1;
        }
    }
}

int KMP(const char *str, int slen, const char *ptr, int plen, int *next) {
    int s_i = 0, p_i = 0;
    while (s_i < slen && p_i < plen) {
        if (str[s_i] == ptr[p_i]) {
            s_i++;
            p_i++;
        } else {
            if (p_i == 0) {
                s_i++;
            } else {
                p_i = next[p_i - 1] + 1;
            }
        }
    }
    return (p_i == plen) ? (s_i - plen) : -1;
}

int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    int next[N], T;//定义next数组
    input(T);
    string data[61];//储存输入的字串
    while (T--) {
        int num;
        scanf("%d", &num);
        char temp[600];//呃，用scanf读入 快一些嘛
        for (int i = 0; i < num; ++i) {
            scanf("%s", temp);
            data[i] = temp;
        }
        int start = 0, length = 3, len = data[0].length();
        string ans = "";
        int max_length = 0;
        while (1) {
            string str = data[0].substr(start, length);//切割一个字串出来
            cal_next(str.c_str(), next, str.length());//计算next数组
            int i;
            for (i = 1; i < num; ++i) {
                if (KMP(data[i].c_str(), data[i].length(), str.c_str(), str.length(), next) == -1) {
                    break;//如果有匹配失败的，就说明这个字串不行，break
                }
            }
            if (i == num) {//如果全部匹配
                if (ans.length() <= str.length()) {//把这个字串赋值给ans
                    if (ans.length() == str.length()) {
                        if (ans > str)ans = str;
                    } else {
                        ans = str;
                    }
                }
                max_length = length;//保存这个字串的长度，用来作为切割一个初始字串的初始长度
                if(start + length == len){//优化，减少不必要的枚举量
                    break;
                }
                ++length;//增长字串的长度进行下一轮匹配
            }
            else{
                start++;//匹配失败，把字串串首往后挪一位
                length = (max_length == 0 ? 1 : max_length);//赋值一个初始长度，如果有匹配到的字串，就是这个字串的长度，不然就是3
            }
            if(start + length > len){//优化，减少枚举量
                break;
            }
        }
        if (ans.length() >= 3) printf("%s\n", ans.c_str());
        else printf("no significant commonalities\n");
    }
//测试用，输出时间
#ifdef LOCAL
    printf("Time used = %02f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}