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

int Queue_Pos[9];
int ccount;

bool Check(int Current_Row){
    int i = 1;
    while(i < Current_Row){
        if(Queue_Pos[i] == Queue_Pos[Current_Row] || abs(Queue_Pos[i] - Queue_Pos[Current_Row]) == abs(i - Current_Row) )
            return false;
        ++i;
    }
    return true;
}

void print(){
    for (int i = 1; i <= 8; ++i) {
        printf("%d",Queue_Pos[i]);
    }
    printf("\n");
}

void solve(int Current_Row,int k){
    if(ccount == k)return ;
    if(Current_Row == 9){
        ccount++;
        if(ccount == k){
            //输出
            print();
        }
        return ;
    }
    for (int i = 1; i <= 8; ++i) {
        Queue_Pos[Current_Row] = i;
        if(Check(Current_Row)){
            solve(Current_Row + 1,k);
        }
    }
}



int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    int T;
    input(T);
    while(T--){
        int k;
        input(k);
        ccount = 0;
        memset(Queue_Pos,0,sizeof Queue_Pos);
        solve(1,k);
    }
    return 0;
}