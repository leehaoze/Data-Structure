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
#define INF 99999999


int cases = 1;
int map[201][201];
int map_ori[201][201];
int love[201];

void Floyd(int n) {
    //Floyd
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == j)continue;
                if (map[i][j] > map[i][k] + map[k][j]) {
                    map[i][j] = map[i][k] + map[k][j];
                    map[j][i] = map[i][j];
                }
            }
        }
    }
}

void Init(int n, int m) {
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if(i == j) {
                map[i][j] = 0;
                map_ori[i][j] = 0;
            }
            map[i][j] = INF;
            map_ori[i][j] = INF;
        }
        love[i] = 0;
    }
    //景点喜好程度
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &love[i]);
    }

    for (int i = 1; i <= m; ++i) {
        int start, end, length;
        scanf("%d%d%d", &start, &end, &length);
        if (map[start][end] > length) {
            map[start][end] = length;
            map_ori[start][end] = length;
        }
        if (map[end][start] > length) {
            map[end][start] = length;
            map_ori[end][start] = length;
        }
    }
    Floyd(n);
}

void Operator_Zero(int n) {
    int x, h;
    scanf("%d%d", &x, &h);
    love[x] += h;
    for (int i = 1; i <= n; ++i) {
        if(map_ori[x][i] != INF){
            love[i]+=h;
        }
    }
}

void Operator_One() {
    int x;
    scanf("%d", &x);
    printf("%d : %d\n", x, love[x]);
}

void Operator_Two(int n) {
    int x, y, length;
    scanf("%d%d%d", &x, &y, &length);

    map_ori[x][y] = length;
    map_ori[y][x] = length;

    if (map[x][y] > length)
        map[x][y] = length;

    if (map[y][x] > length)
        map[y][x] = length;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j)continue;
            if (map[i][j] > map[i][x] + map[x][j]) {
                map[i][j] = map[i][x] + map[x][j];
                map[j][i] = map[i][j];
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j)continue;
            if (map[i][j] > map[i][y] + map[y][j]) {
                map[i][j] = map[i][y] + map[y][j];
                map[j][i] = map[i][j];
            }
        }
    }

}

void Operator_Three() {
    int x, y;
    scanf("%d%d", &x, &y);
    if (map[x][y] == INF) {
        printf("No such path.\n");
    } else {
        printf("%d -> %d : %d\n", x, y, map[x][y]);
    }
}

int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        Init(n, m);
        //Input  Order
        printf("Case #%d:\n", cases++);
        for (int i = 0; i < k; ++i) {
            int order;
            scanf("%d", &order);
            if(order == 0){
                int x, h;
                scanf("%d%d", &x, &h);
                love[x] += h;
                for (int i = 1; i <= n; ++i) {
                    if(map_ori[x][i] != INF){
                        love[i]+=h;
                    }
                }
            }
            else if(order == 1){
                int x;
                scanf("%d", &x);
                printf("%d : %d\n", x, love[x]);
            }
            else if(order == 2){
                int x, y, length;
                scanf("%d%d%d", &x, &y, &length);

                map_ori[x][y] = length;
                map_ori[y][x] = length;

                if (map[x][y] > length)
                    map[x][y] = length;

                if (map[y][x] > length)
                    map[y][x] = length;

                for (int i = 1; i <= n; ++i) {
                    for (int j = 1; j <= n; ++j) {
                        if (i == j)continue;
                        if (map[i][j] > map[i][x] + map[x][j]) {
                            map[i][j] = map[i][x] + map[x][j];
                            map[j][i] = map[i][j];
                        }
                    }
                }

                for (int i = 1; i <= n; ++i) {
                    for (int j = 1; j <= n; ++j) {
                        if (i == j)continue;
                        if (map[i][j] > map[i][y] + map[y][j]) {
                            map[i][j] = map[i][y] + map[y][j];
                            map[j][i] = map[i][j];
                        }
                    }
                }

            }
            else if(order == 3){
                int x, y;
                scanf("%d%d", &x, &y);
                if (map[x][y] == INF) {
                    printf("No such path.\n");
                } else {
                    printf("%d -> %d : %d\n", x, y, map[x][y]);
                }
            }
        }
    }
    return 0;
}