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

#define INF 99999999

int n;
int map[101][101];
int dis[101];
bool Hash[101];

void Init() {
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            map[i][j] = INF;
        }
        Hash[i] = false;
    }
}

void Input_Data() {
    for (int i = 1; i <= n; ++i) {
        int num;
        scanf("%d", &num);
        for (int j = 0; j < num; ++j) {
            int b, weight;
            scanf("%d%d", &b, &weight);
            if (map[i][b] > weight)
                map[i][b] = weight;
        }
    }
}

int Dijkstra(int num) {
    for (int i = 0; i <= n; ++i) {
        dis[i] = map[num][i];
    }
    dis[num] = 0;
    Hash[num] = true;

    for (int i = 1; i <= n; ++i) {
        int min_dis = INF;
        int min_num = 0;
        for (int j = 1; j <= n; ++j) {
            if (!Hash[j] && min_dis > dis[j]) {
                min_dis = dis[j];
                min_num = j;
            }
        }
        if(min_dis == INF)continue;
        Hash[min_num] = true;
        for (int j = 1; j <= n; ++j) {
            if (!Hash[j] && map[min_num][j] < INF) {
                if (dis[min_num] + map[min_num][j] < dis[j]) {
                    dis[j] = dis[min_num] + map[min_num][j];
                }
            }
        }
    }
    int ans = -1;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, dis[i]);
    }

    return ans;
}

void Get_Ans() {
    int ans = INF;
    int num;
    for (int i = 1; i <= n; ++i) {
        int temp = Dijkstra(i);
        if (ans > temp) {
            ans = temp;
            num = i;
        }
    }
    if(ans == INF)printf("disjoint\n");
    else printf("%d %d\n", num, ans);
}


int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    while (scanf("%d", &n) != EOF) {
        if (n == 0)break;
        Init();
        Input_Data();
        Get_Ans();
    }
    return 0;
}