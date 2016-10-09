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

const int N = 62;
const int M = 510;
const int KMPSIZE = 510;

class KMP {
    int nxt[KMPSIZE];//nxt[i]=j表示i长的前缀的除本身外的最长后缀为前j长的前缀
    int len;
    char *t;

    void getnxt() {
        nxt[1] = 0;
        for (int q = 2, k = 0; q <= len; q++) {
            while (k > 0 && t[k + 1] != t[q])k = nxt[k];
            if (t[k + 1] == t[q])k++;
            nxt[q] = k;
        }
    }

public:
    void init(char mode[]) {
        t = mode;
        len = strlen(t + 1);
        getnxt();
    }

    int kmp(char s[], int sl) {
        int mm = -1;
        for (int i = 1, q = 0; i <= sl; i++) {
            while (q > 0 && t[q + 1] != s[i])q = nxt[q];
            q += int(t[q + 1] == s[i]);
            mm = max(mm, q);
            if (q == len) {
                return mm;
            }
        }
        return mm;
    }
};

KMP kmp;
char s[N][M];
char ans[M];

int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    int n;
    int T;
    input(T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%s", s[i] + 1);
        }
        char tmp[M];
        int cnt = 0;
        int len = strlen(s[1] + 1);
        for (int i = 1; i <= len && len - i + 1 >= cnt; i++) {
            strcpy(tmp + 1, s[1] + i);
            kmp.init(tmp);
            // printf("debug %s\n",tmp+1);
            int mm = len - i + 1;
            for (int j = 2; j <= n && mm >= cnt; j++) {
                mm = min(mm, kmp.kmp(s[j], strlen(s[j] + 1)));
            }
            tmp[mm + 1] = 0;
            //  printf("debug 2 %s\n",tmp+1);
            if (mm > cnt || (mm == cnt && strcmp(tmp + 1, ans + 1) < 0)) {
                cnt = mm;
                strcpy(ans + 1, tmp + 1);
            }
        }
        if (cnt != 0 && strlen(ans + 1) >= 3)
            printf("%s\n", ans + 1);
        else
            printf("no significant commonalities\n");
    }
    return 0;
}