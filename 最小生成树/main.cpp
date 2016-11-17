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

struct Node {
    int num;
    int cost;
    Node(int n, int c) : num(n), cost(c) {}
    Node() : num(0), cost(0) {}
};

bool operator <(const Node &a,const Node &b){
    return a.cost < b.cost;
}

int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    int T;
    input(T);
    int cases = 1;
    while (T--) {
        int n,m,c;
        scanf("%d%d%d",&n,&m,&c);
        vector<Node> *node = new vector<Node> [n+1];
        for (int i = 0; i < m; ++i) {
            int a,b,cost;
            scanf("%d%d%d",&a,&b,&cost);
            node[a].push_back(Node(b,cost));//点a可以到达点b，cost为c
            //node[b].push_back(Node(a,cost));
        }
        for (int i = 1; i <= n; ++i) {
            sort(node[i].begin(),node[i].end());//排序，把cost少的放在前边
        }
        vector<int> A;//记录已经连接的点
        A.push_back(1);//把点1放进去
        int *hash = new int[n+1];
        memset(hash,0,sizeof hash);//hash数组，用来纪录某个点是不是已经修好了路，即是否已经添加到了A中
        hash[1] = 1;
        int *pos_of_node = new int[n+1];//记录每个点已经访问到第几个点了
        memset(pos_of_node,0,sizeof pos_of_node);
        bool find = true;//用于排查－1的情况
        unsigned long long ans = 0;
        while(A.size() < n){//当A中的点的个数不足n个，就继续添加
            int size_of_A = (int)A.size();
            int Min_cost = INF,Min_cost_num = 0;
            for (int i = 0; i < size_of_A; ++i) {//遍历A中的每个点，做为起点
                int start = A.at(i);
                //进入node[start]中，寻找最小花费
                while(pos_of_node[start] < node[start].size() && hash[(node[start].at(pos_of_node[start])).num] == 1){
                    pos_of_node[start]++;
                }
                if(pos_of_node[start] < node[start].size()){
                    if(Min_cost > node[start].at(pos_of_node[start]).cost){
                        Min_cost = node[start].at(pos_of_node[start]).cost;
                        Min_cost_num = node[start].at(pos_of_node[start]).num;
                    }
                }
            }
            if(Min_cost == INF){//如果Min_cost的值没有更改，说明有的点无法抵达了，break输出－1;
                find = false;
                break;
            }
            else{
                ans += Min_cost * c;
                A.push_back(Min_cost_num);
                hash[Min_cost_num] = 1;
            }
        }
        if(find){
            printf("Case #%d: %d\n",cases++,ans);
        }
        else{
            printf("Case #%d: -1\n",cases++);
        }
        delete []node;
        delete []hash;
        delete []pos_of_node;
    }
    return 0;
}