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

struct Node{
    int weight;
    char data;
    Node *lChild,*rChild;
    Node(){
        weight = 0;
        data = ' ';
        lChild = NULL;
        rChild = NULL;
    }
};

//bool operator<(const Node &a,const Node &b){
//    if(a.weight != b.weight)return a.weight < b.weight;
//    else return a.data < b.data;
//}

int cmp(Node *a,Node *b){
    if(a->weight != b->weight)return a->weight < b->weight;
    else return a->data < b->data;
}

int value[27];
string ans[27];
int cases = 1;
vector<Node *>tree;

void Init(){
    for (int i = 0; i < 26; ++i) {
        value[i] = 0;
        ans[i] = "";
    }
    tree.clear();
}

int Cal_Value(string ipt){
    int len = ipt.length();
    for (int i = 0; i < len; ++i) {
        value[ipt[i] - 'A']++;
    }
}

void Init_Tree(){
    for (int i = 0; i < 26; ++i) {
        if(value[i] != 0){
            Node *temp = new Node;
            temp->data = (char)(i + 'A');
            temp->weight = value[i];
            temp->lChild = NULL;
            temp->rChild = NULL;
            tree.push_back(temp);
        }
    }
    sort(tree.begin(),tree.end(),cmp);
}

void Build_Tree(){
    while(tree.size() > 1){
        Node *A = tree.at(0);
        Node *B = tree.at(1);
        tree.erase(tree.begin());
        tree.erase(tree.begin());
        Node *temp = new Node;
        temp->weight = A->weight + B->weight;
        temp->rChild = B;
        temp->lChild = A;
        temp->data = A->data;
        tree.push_back(temp);
        sort(tree.begin(),tree.end(),cmp);
    }
}

void Get_Ans(Node *head,string temp){
    if(head->rChild == NULL && head->lChild == NULL){
        if(temp == "")
            temp = '0';
        ans[head->data - 'A'] = temp;
    }
    else{
        Get_Ans(head->lChild,temp + '0');
        Get_Ans(head->rChild,temp + '1');
    }
}

void Change_Order(){
    for (int i = 0; i < 26; ++i) {
        if(value[i] == 0)continue;
        for (int j = i + 1; j < 26; ++j) {
            if(value[i] == value[j]){
                if(ans[i] > ans[j])swap(ans[i],ans[j]);
            }
        }
    }
}

void Print(string ipt){
    for (int i = 0; i < 26; ++i) {
        if(value[i] != 0){
            printf("%c: %s\n",i + 'A',ans[i].c_str());
        }
    }
    int len = ipt.length();
    string ans_code = "";
    for (int i = 0; i < len; ++i) {
        ans_code += ans[ipt[i] - 'A'];
    }
    len = ans_code.length();
    printf("%d",len);
    if(len < 50){
        printf(" %s",ans_code.c_str());
    }
    printf("\n");
}

void Delete_Tree(Node *node){
    if(node->lChild)
        Delete_Tree(node->lChild);
    if(node->rChild)
        Delete_Tree(node->rChild);
    delete node;
}


int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    string ipt;
    while(cin >> ipt){
        Init();
        Cal_Value(ipt);
        Init_Tree();
        Build_Tree();
        Get_Ans(tree.at(0),"");
        Change_Order();
        printf("Case #%d:\n",cases++);
        Print(ipt);
        Delete_Tree(tree.at(0));
    }
    return 0;
}