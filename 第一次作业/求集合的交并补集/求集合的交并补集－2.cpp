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

#define MAXN 99999 //这个本应该是2的31次方的，结果是开不出来的，就想着试试可不可以钻空子呐

int Hash[MAXN];//正整数的hash表
int Hash2[MAXN];//负的

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

LinkList Create_Set(int num) {
    LinkList L = new LNode;
    L->next = NULL;//记得建一个新的就把next指向NULL
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

void Free_Set(LinkList &L){//为了不MLE
    while(L){
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

void set_difference(LinkList &La, LinkList &Lb) {//hash表的方法 把两个链表各自遍历一遍，比直接两层循环是快许多，然而是开不出来的
    memset(Hash, 0, sizeof(Hash));
    memset(Hash2, 0, sizeof(Hash2));
    LinkList pa = La->next;
    LinkList pb = Lb->next;
    while (pa) {
        if(pa->data >= 0)
            Hash[pa->data] = 1;
        else
            Hash2[-(pa->data)] = 1;
        pa = pa->next;
    }
    bool first_print = true;
    while (pb) {
        if ((pb->data >= 0 ? Hash[pb->data] : Hash2[-(pb->data)]) == 1) {
            if (!first_print) printf(" ");
            printf("%d", pb->data);
            if (first_print)
                first_print = false;
        }
        pb = pb->next;
    }
    printf("\n");
}

void set_minus(LinkList &La, LinkList &Lb) {
    memset(Hash, 0, sizeof(Hash));
    memset(Hash2, 0, sizeof(Hash2));
    LinkList pa = La->next;
    LinkList pb = Lb->next;
    while (pb) {
        if(pb->data >= 0)
            Hash[pb->data] = 1;
        else
            Hash2[-(pb->data)] = 1;
        pb = pb->next;
    }
    bool first_print = true;
    while (pa) {
        if ((pa->data >= 0 ? Hash[pa->data] : Hash2[-(pa->data)]) == 0) {
            if (!first_print) printf(" ");
            printf("%d", pa->data);
            if (first_print) first_print = false;
        }
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