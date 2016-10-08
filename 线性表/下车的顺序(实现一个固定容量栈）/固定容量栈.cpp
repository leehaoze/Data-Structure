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

typedef struct{
    int *base;
    int *top;
    int size;
}SqStack;

void Creat_empty_Stack(SqStack &s,int num){
    s.base = new int[num];
    s.size = num;
    s.top = s.base;
}

void Free_Stack(SqStack &s){
    s.top = NULL;
    free(s.base);
}

void Push(SqStack &s,int num){
    if(s.top - s.base == s.size)
        return ;
    *(s.top) = num;
    s.top++;
}

int Top(SqStack &s){
    if(s.top != s.base)
        return *(s.top - 1);
    return -1;
}

int Pop(SqStack &s){
    if(s.top != s.base)
        s.top--;
}

int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    int T, cases = 1;
    scanf("%d", &T);
    while (T--) {
        printf("Case #%d:\n", cases++);
        int n,c;
        scanf("%d%d",&n,&c);
        SqStack bus;
        Creat_empty_Stack(bus,c);//初始化一个空的bus
        for (int i = 0; i < n; ++i) {//n组指令
            int order;
            input(order);
            if(order == 0){
                int num;
                input(num);
                for (int j = 0; j < num; ++j) {
                    if(j != 0) print_one_blank;
                    printf("%d",Top(bus));
                    Pop(bus);
                }
                printf("\n");
            }
            else{
                for (int j = 0; j < order; ++j) {
                    int num;
                    input(num);
                    Push(bus,num);
                }
            }
        }
        Free_Stack(bus);
    }
    return 0;
}