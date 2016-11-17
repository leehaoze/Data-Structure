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
#define INF 999999

struct CEdge {
    int u;
    int v;
    int weight;

    CEdge() {}

    CEdge(int u, int v, int w) : u(u), v(v), weight(w) {}
};


int *root;


bool compare(CEdge a, CEdge b) {
    return a.weight < b.weight;//ÉýÐò..
}

int Find(int x) {
    return root[x];
}

void Union(int a, int b, int V) {
    int root_a = Find(a);
    int root_b = Find(b);
    if (root_a != root_b) {
        root[b] = root_a;
        //如果a，b不在同一棵树，要把b所在树的所有顶点都移植过去给a...
        for (int i = 1; i <= V; i++)
            if (root[i] == root_b)
                root[i] = root_a;
    }
}

unsigned long long Kruskal(int V, int E, CEdge *e) {
    for (int i = 1; i <= V; i++)
        root[i] = i;

    //order by weight in edge
    sort(e, e + E, compare);
    int count = 0;
    unsigned long long ans = 0;
    for (int i = 0; i < E; i++)
        if (Find(e[i].u) != Find(e[i].v)) {
            count++;
            ans += e[i].weight;
            Union(e[i].u, e[i].v, V);
        }
    if(count == V - 1)return ans;
    else return -1;
}

int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    int T;
    input(T);
    int cases = 1;
    while (T--) {
        int n, m, c;
        scanf("%d%d%d", &n, &m, &c);
        CEdge *edges = new CEdge[m + 1];
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &edges[i].v, &edges[i].u, &edges[i].weight);
        }
        root = new int[n + 1];
        printf("Case #%d: %d\n",cases++,Kruskal(n,m,edges) * c);
        delete []edges;
        delete []root;
    }
    return 0;
}


//
//struct Node {
//    int numA;
//    int numB;
//    int cost;
//
//    Node(int a, int b, int c) : numA(a), numB(b), cost(c) {}
//
//    Node() : numA(0), numB(0), cost(0) {}
//};
//
//bool operator<(const Node &a, const Node &b) {
//    return a.cost < b.cost;
//}
//
//int main() {
//#ifdef LOCAL
//    freopen("IN.txt", "r", stdin);
//#endif
//    int T;
//    input(T);
//    int cases = 1;
//    while (T--) {
//        int n, m, c;
//        scanf("%d%d%d", &n, &m, &c);
//        Node *node = new Node[m + 1];
//        for (int i = 0; i < m; ++i) {
//            scanf("%d%d%d",&node[i].numA,&node[i].numB,&node[i].cost);
//        }
//        sort(node,node+m);
////        for (int i = 0; i < m; ++i) {
////            cout << node[i].numA << " " << node[i].numB << " " << node[i].cost << endl;
////        }
//        int hash[n+1];
//        int count = 2;
//        unsigned long long ans = 0;
//        memset(hash,0,sizeof(hash));
//        hash[node[0].numA] = 1;
//        hash[node[0].numB] = 1;
//        ans += node[0].cost;
//        for (int i = 1; i < m; ++i) {
////            cout << node[i].numA << " " << node[i].numB << " " << node[i].cost << " ";
////            cout << hash[node[i].numA] << " " << hash[node[i].numB] << endl;
//            if( (hash[node[i].numA] == 1 && hash[node[i].numB] == 0) || (hash[node[i].numA] == 0 && hash[node[i].numB] == 1) ){
//                ans = ans + node[i].cost;
//                if(hash[node[i].numA] == 0){
//                    hash[node[i].numA] = 1;
//                    ++count;
//                }
//                else{
//                    hash[node[i].numB] = 1;
//                    ++count;
//                }
//            }
//        }
//        if(count != n){
//            printf("Case #%d: -1\n",cases++);
//        }
//        else{
//            printf("Case #%d: %llu\n",cases++,ans * c);
//        }
//        delete []node;
//    }
//    return 0;
//}