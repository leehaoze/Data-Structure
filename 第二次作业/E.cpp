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

int deepth;

void Cal_Deep(vector<int> *data, int num, int deep) {
    deepth = max(deepth, deep);
    int size = data[num].size();
    for (int i = 0; i < size; ++i) {
        Cal_Deep(data, data[num].at(i), deep + 1);
    }
}

void Tree_to_Binary(vector<int> *data, vector<int> *data_binary, int num) {
    int size = data[num].size();
    for (int i = size - 1; i > 0; --i) {
        data_binary[data[num].at(i-1)].push_back(data[num].at(i));
    }
    if(data[num].size() >= 1)
        data_binary[num].push_back(data[num].at(0));
    for (int i = 0; i < size; ++i) {
        Tree_to_Binary(data,data_binary,data[num].at(i));
    }
}

int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    int n;
    vector<int> data[30001];
    vector<int> data_binary[30001];
    int fa[30001];
    while (scanf("%d", &n) != EOF) {
        memset(fa,0,sizeof fa);
        for (int i = 0; i <= n; ++i) {
            data[i].clear();
            data_binary[i].clear();
        }
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            data[a].push_back(b);
            fa[b] = a;
        }

        int root;

        for (int i = 1; i <= n; ++i) {
            if(fa[i] == 0)
                root = i;
        }

        deepth = 0;
        Cal_Deep(data,root, 1);
        printf("%d ", deepth);
        deepth = 0;
        Tree_to_Binary(data, data_binary, root);
        Cal_Deep(data_binary,root, 1);
        printf("%d\n", deepth);
    }
    return 0;
}