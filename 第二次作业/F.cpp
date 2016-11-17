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

const int MAX = 99999999;

int map[310][310];
int book[310];

void Init(int n){
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n ; ++j) {
            map[i][j] = MAX;
        }
    }
}

void Input(int m){
    for (int i = 0; i < m; ++i) {
        int u,v,d;
        scanf("%d%d%d",&u,&v,&d);
        if(map[u][v] > d)
            map[u][v] = d;
    }
}

void Floyd(int n){
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if(i == j)continue;
                if(map[i][j] > (map[i][k] + map[k][j]) ){
                    map[i][j] = (map[i][k] + map[k][j]);
                }
            }
        }
    }
}

void Select(int n){
    int num = -1,length = MAX,max_length = MAX;
    for (int i = 1; i <= n; ++i) {
        int l = 0;//length
        int m = -1;//max_length
        for (int j = 1; j <= n; ++j) {
            if(i == j)continue;
            if(map[i][j] != MAX && map[j][i] != MAX){
                l += (map[i][j] + map[j][i]);//往返
                m = max(m,map[i][j] + map[j][i]);
            }
            else{
                l = -1;
                m = -1;
            }
        }
        if(l != -1 && m != -1){
            if(max_length > m){
                num = i;
                length = l;
                max_length = m;
            }
            else if(max_length == m){
                if(length > l){
                    num = i;
                    length = l;
                    max_length = m;
                }
                else if(length == l){
                    if(num > i){
                        num = i;
                        length = l;
                        max_length = m;
                    }
                }
            }
        }
    }
    if(num == -1){
        printf("-1\n\n");
    }
    else{
        printf("%d %d %d\n\n",num,max_length,length);
    }
}

int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    int T,cases = 1;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        Init(n);
        Input(m);
        Floyd(n);
//        printf("Case #%d:\n",cases++);
//        Select(n);
        int pos = 0, con1 = 99999999, con2 = 99999999;
        memset(book, 0, sizeof book);
        for (int i = 1; i <= n; i++) {
            if (book[i])
                continue;
            int sum = 0, sigle = 0;
            bool ok = true;
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                if (map[i][j] < MAX && map[j][i] < MAX) {
                    if (sigle < map[i][j] + map[j][i])
                        sigle = map[i][j] + map[j][i];
                    sum += map[i][j] + map[j][i];
                } else {
                    ok = false;
                    book[i] = book[j] = 1;
                    break;
                }
            }
            if (ok) {
                if (con1 > sigle) {
                    con1 = sigle;
                    con2 = sum;
                    pos = i;
                } else if (con1 == sigle) {
                    if (con2 > sum) {
                        con2 = sum;
                        pos = i;
                    }
                }
            }
        }
        printf("Case #%d:\n", cases++);
        if (pos != 0) {
            printf("%d %d %d\n\n", pos, con1, con2);
        } else {
            printf("-1\n\n");
        }
    }
    return 0;
}