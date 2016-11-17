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


typedef struct LNode {
    int num;
    int data;
    struct LNode *next;
} LNode, *LinkList;

LinkList Creat_Cycle(int num) {//创建一个长度为num的约瑟夫环
    LinkList L = new LNode;
    L->next = L;
    L->data = -1;
    LinkList pL = L;
    for (int i = 0; i < num; ++i) {
        LinkList temp = new LNode;
        scanf("%d",&temp->data);
        temp->num = i + 1;
        temp->next = L->next;
        pL->next = temp;
        pL = pL->next;
    }
    return L;
}

void Free_Cycle(LinkList &L) {//释放内存
//    LinkList pL;
//    while(L->next != L){//这个地方的终止条件就不是之前的pL不指向NULL了 ||这个为什么错呐～，因为头节点已经被删掉了
//        pL = L;
//        L = L->next;
//        free(pL);
//    }
    //第二次写的，完善了一些 ，然后突然想明白，这个链表已经被删的只剩下头节点和一个元素了
//    LinkList head = L->next;
//    LinkList phead = head->next;
//    LinkList temp;
//    while(phead != head){
//        temp = phead;
//        phead = phead->next;
//        free(temp);
//    }
//    free(head);
//    free(L);
//    LinkList
//    free(L->next);
//    free(L);
}

void go(LinkList &L){
    LinkList pL = L->next;
    int first_print = true;
    while(pL->next != pL){
        int times = pL->data - 1;//走到选中人之前的那个人就可以，方便删除
        for (int i = 0; i < times; ++i) {
            pL = pL->next;
            if(pL->data == -1) pL = pL->next;//如果走到了头节点，跳过去
        }
        LinkList out_people = pL->next;
        if(!first_print)printf(" ");
        if(first_print)first_print = false;
        printf("%d",out_people->num);
        pL->next = out_people->next;
        pL = pL->next;
        free(out_people);
    }
    //因为就剩下两个LNode了，而且L->next不是pL，所以直接在这里删了吧
    free(pL);
    free(L);
    printf("\n");
}

int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    int T, cases = 1;
    scanf("%d", &T);
    while (T--) {
        int num_of_people;
        scanf("%d", &num_of_people);
        LinkList Cycle = Creat_Cycle(num_of_people);
        printf("Case #%d:\n", cases++);
        go(Cycle);
        //Free_Cycle(Cycle);
    }
    return 0;
}