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

int ansA,ansB;

void dfs(vector<int> *data, int root,int d1,int d2){
    if(d1 > ansA)ansA = d1;
    if(d2 > ansB)ansB = d2;
    int len = data[root].size();
    int m = 1;
    for (int i = 0; i < len; ++i,m++) {
        dfs(data,data[root].at(i),d1 + 1,d2 + m);
    }
}

int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    int n;
    vector<int> data[30001];
    int fa[30001];
    while (~scanf("%d", &n)) {
        memset(fa,0,sizeof fa);
        for (int i = 0; i < 30001; ++i) {
            data[i].clear();
        }
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            data[a].push_back(b);
            fa[b]++;
        }

        int root;

        for (int i = 1; i <= n; ++i) {
            if(fa[i] == 0) {
                root = i;
                break;
            }
        }

        ansA = 0;
        ansB = 0;
        dfs(data,root,1,1);

        printf("%d %d\n",ansA,ansB);
    }
    return 0;
}