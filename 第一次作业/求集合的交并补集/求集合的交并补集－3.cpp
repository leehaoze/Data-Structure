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

#define MAXN 99999

int Hash[MAXN];
int Hash2[MAXN];

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

LinkList Create_Set(int num) {
    LinkList L = new LNode;
    L->next = NULL;
    LinkList pL = L;
    for (int i = 0; i < num; ++i) {
        LinkList temp = new LNode;
        temp->next = NULL;
        scanf("%d", &temp->data);
        pL->next = temp;
        pL = pL->next;
    }
    return L;
}

void Free_Set(LinkList &L) {
    while (L) {
        LinkList pL;
        pL = L;
        L = L->next;
        free(pL);
    }
}

void set_union(LinkList &La, LinkList &Lb) {
    LinkList pa = La->next;
    LinkList pb = Lb->next;
    bool first_print = true;
    while (pa && pb) {
        if (!first_print) printf(" ");
        if (pa->data == pb->data) {
            printf("%d", pa->data);
            pa = pa->next;
            pb = pb->next;
        } else if (pa->data < pb->data) {
            printf("%d", pa->data);
            pa = pa->next;
        } else {
            printf("%d", pb->data);
            pb = pb->next;
        }
        if (first_print)
            first_print = false;
    }
    while (pa) {
        if (!first_print) printf(" ");
        printf("%d", pa->data);
        pa = pa->next;
    }
    while (pb) {
        if (!first_print) printf(" ");
        printf("%d", pb->data);
        pb = pb->next;
    }
    printf("\n");
}


void set_difference(LinkList &La, LinkList &Lb) {//两个指针往后走，因为是按升序排列的，所以呐，如果pa->data < pb->data，就说明，pa->data在B中没有出现过，a=b，说明出现过，a>b,同理 很简单的道理
    LinkList pa = La->next;
    LinkList pb = Lb->next;
    bool first_print = true;
    while(pa && pb){
        if(pa->data < pb->data){
            pa = pa->next;
        }
        else if(pa->data == pb->data){
            if(!first_print)printf(" ");
            printf("%d",pa->data);
            if(first_print)first_print = false;
            pa = pa->next;
            pb = pb->next;
        }
        else{
            pb = pb->next;
        }
    }
    printf("\n");
}

void set_minus(LinkList &La, LinkList &Lb){
    LinkList pa = La->next;
    LinkList pb = Lb->next;
    bool first_print = true;
    while(pa && pb){
        if(pa->data < pb->data){
            if(!first_print)printf(" ");
            printf("%d",pa->data);
            if(first_print)first_print = false;
            pa = pa->next;
        }
        else if(pa->data == pb->data){
            pa = pa->next;
            pb = pb->next;
        }
        else{
            pb = pb->next;
        }
    }
    while(pa){
        if(!first_print)printf(" ");
        printf("%d",pa->data);
        if(first_print)first_print = false;
        pa = pa->next;
    }
    printf("\n");
}

int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    int T;
    scanf("%d", &T);
    int cases = 1;
    while (T--) {
        int numa, numb;
        scanf("%d", &numa);
        LinkList set_A = Create_Set(numa);
        scanf("%d", &numb);
        LinkList set_B = Create_Set(numb);
        printf("Case #%d:\n", cases++);
        set_difference(set_A, set_B);
        set_union(set_A, set_B);
        set_minus(set_A, set_B);
        set_minus(set_B, set_A);
        Free_Set(set_A);
        Free_Set(set_B);
    }
    return 0;
}