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

typedef struct Node {
    int num;
    vector<Node *> child;
} Node;

void Creat_Tree(Node *head, vector<int> *data, int num) {
    int size = data[num].size();
    for (int i = 0; i < size; ++i) {
        Node *temp = new Node;
        temp->num = data[num].at(i);
        head->child.push_back(temp);
        Creat_Tree(temp, data, data[num].at(i));
    }
}

void Print_Tree(Node *head) {
    stack<Node *> S;
    S.push(head);
    while (!S.empty()) {
        Node *temp = S.top();
        S.pop();
        cout << temp->num << endl;
        int size = temp->child.size();
        for (int i = 0; i < size; ++i) {
            S.push(temp->child.at(i));
        }
    }
}

int deepth;

int Cal_deep_of_Tree(Node *head, int deep) {
    deepth = max(deepth, deep);
    int size = head->child.size();
    for (int i = 0; i < size; ++i) {
        Cal_deep_of_Tree(head->child.at(i), deep + 1);
    }
}


void Cal_deep_from_Vector(vector<int> *data, int num, int deep) {
    deepth = max(deepth, deep);
    int size = data[num].size();
    for (int i = 0; i < size; ++i) {
        Cal_deep_from_Vector(data, data[num].at(i), deep + 1);
    }
}

void Tree_to_Binary(vector<int> *data, int num) {
    int size = data[num].size();
    if (size > 2) {
        for (int i = 0; i < size; ++i) {
            Tree_to_Binary(data, data[num].at(i));
        }
        for (int i = size - 1; i > 1; --i) {
            data[data[num].at(i - 1)].push_back(data[num].at(i));
            data[num].erase(data[num].begin() + i);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    int n;
    while (scanf("%d", &n) != EOF) {
        vector<int> *data = new vector<int>[n + 1];
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            data[a].push_back(b);
        }

        for (int i = 1; i <= n; ++i) {
            sort(data[i].begin(), data[i].end());
        }

        deepth = 0;
//        for (int i = 1; i <= n; ++i) {
//            cout << "i is " << i << ':';
//            for (int j = 0; j < data[i].size(); ++j) {
//                cout << data[i].at(j) << ' ';
//            }
//            cout << endl;
//        }
        Cal_deep_from_Vector(data, 1, 1);
        cout << deepth << ' ';
        Tree_to_Binary(data, 1);
//        for (int i = 1; i <= n; ++i) {
//            cout << "i is " << i << ':';
//            for (int j = 0; j < data[i].size(); ++j) {
//                cout << data[i].at(j) << ' ';
//            }
//            cout << endl;
//        }
        deepth = 0;
        Cal_deep_from_Vector(data, 1, 1);
        cout << deepth << endl;
        delete[]data;
    }


    return 0;
}