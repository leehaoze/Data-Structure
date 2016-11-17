//NCC_31060 Majestic
#include <iostream>
#include <deque>
#include <map>
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

map<string, int> Dic;

struct Course {
    int in_;
    string name_;
    vector<Course *> next;
};

bool operator<(const Course &A, const Course &B) {
    return A.name_ < B.name_;
}

Course course[5001];
int cases = 1;

int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    int T;
    scanf("%d",&T);
    while (T--) {
        Dic.clear();
        int n;
        input(n);
        for (int i = 0; i < n; ++i) {
            char name[1010];
            scanf("%s",&name);
            course[i].name_ = name;
            course[i].in_ = 0;
        }
        sort(course,course + n);
        for (int i = 0; i < n; ++i) {
            Dic.insert(make_pair(course[i].name_, i));
        }
        int m;
        input(m);
        while (m--) {
            char A[1010],B[1010];
            scanf("%s%s",&A,&B);
            int numA = Dic[A];
            int numB = Dic[B];
            course[numA].next.push_back(&course[numB]);
            course[numB].in_++;
        }
        printf("Case %d:\n",cases++);
        queue<Course *> Q;
        for (int i = 0; i < n; ++i) {
            if (course[i].in_ == 0) {
                Q.push(&course[i]);
                break;
            }
        }
        while (!Q.empty()) {
            Course *head = Q.front();
            head->in_ = -1;

            Q.pop();
            printf("%s\n", head->name_.c_str());
            int size = head->next.size();
            for (int i = 0; i < size; ++i) {
                head->next.at(i)->in_--;
            }
            head->next.clear();
            for (int i = 0; i < n; ++i) {
                if (course[i].in_ == 0) {
                    Q.push(&course[i]);
                    break;
                }
            }
        }
    }

    return 0;
}