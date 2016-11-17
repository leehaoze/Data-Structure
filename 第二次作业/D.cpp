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
#include <set>

using namespace std;

#define input(a) scanf("%d",&a);
#define print_one_blank printf(" ");

int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    int n, q;
    int father[50001];
    int deep[50001];
    while (scanf("%d%d", &n, &q) != EOF) {
        for (int i = 0; i <= n; ++i) {
            deep[i] = 0;
        }
        for (int i = 0; i < n - 1; ++i) {
            int a,b;
            scanf("%d%d",&a,&b);
            father[b] = a;
            deep[b] = deep[a] + 1;
        }
        for (int i = 0; i < q; ++i) {
            int a,b;
            scanf("%d%d",&a,&b);
            while(deep[a] > deep[b]){
                a = father[a];
            }
            while(deep[a] < deep[b]){
                b = father[b];
            }
            while(a != b){
                a = father[a];
                b = father[b];
            }
            printf("%d\n",a);
        }
    }
    return 0;
}