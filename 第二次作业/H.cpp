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

struct edge {
    int u, v, w;
};

bool operator<(const edge &a, const edge &b) {
    return a.w < b.w;
}

int n, m;

int getf(int v, int *f) {
    if (f[v] == v)
        return v;
    else {
        f[v] = getf(f[v], f);
        return f[v];
    }
}

int merge(int v, int u, int *f) {
    int t1, t2;
    t1 = getf(v, f);
    t2 = getf(u, f);
    if (t1 != t2) {
        f[t2] = t1;
        return 1;
    }
    return 0;
}



int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    int T;
    int cases = 1;
    input(T);
    while (T--) {
        int c,count = 0;
        unsigned long long sum = 0;
        scanf("%d%d%d", &n, &m, &c);
        struct edge *e = new edge[m+1];
        for (int i = 1; i <= m; ++i) {
            scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
        }
        sort(e, e + m + 1);
        int *f = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            f[i] = i;
        }
        bool fine = false;
        for (int i = 1; i <= m; ++i) {
            if (merge(e[i].u, e[i].v, f)) {
                ++count;
                sum = sum + e[i].w;
            }
            if (count == n - 1){
                fine = true;
                break;
            }
        }
        if(fine)
            printf("Case #%d: %llu\n", cases++, sum * (unsigned long long )c);
        else
            printf("Case #%d: -1\n", cases++);
        delete[]f;
        delete []e;
    }
    return 0;
}