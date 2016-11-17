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

int cases = 1;

int map[10][10];
int visit[10][10];
int n, x, y;
int jump_x[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int jump_y[] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool jump_out = false;

void Horse_Jump(int x, int y, int deep) {
    map[x][y] = deep;

    if (jump_out)return;

    if (deep == n * n) {
        jump_out = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                printf("%3d", map[i][j]);
            }
            printf("\n");
        }
        return;
    } else {
        int next_x, next_y;
        for (int i = 0; i < 8; ++i) {
            next_x = x + jump_x[i];
            next_y = y + jump_y[i];
            if (next_x > 0 && next_x <= n && next_y > 0 && next_y <= n && visit[next_x][next_y] != 1) {
                visit[next_x][next_y] = 1;
                Horse_Jump(next_x, next_y, deep + 1);
                if (jump_out)return;
                visit[next_x][next_y] = 0;
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &x, &y);
        memset(map, 0, sizeof map);
        memset(visit, 0, sizeof visit);
        printf("Case #%d:\n", cases++);
        visit[x][y] = 1;
        jump_out = false;
        Horse_Jump(x, y, 1);
        if (!jump_out)printf("No solution.\n");
    }

#ifdef LOCAL
    printf("Time used = %02f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}