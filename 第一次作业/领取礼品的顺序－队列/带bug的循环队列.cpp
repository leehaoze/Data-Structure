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

#define INITSIZE 150000
#define INCRSIZE 150000

typedef struct Queue {
    int size;   //数组的大小
    int head, tail;  //队列的头和尾下标
    int *data;          //数组头指针
} Queue;

void Init_Queue(Queue &q) {
    q.data = new int[INITSIZE];
    q.size = INITSIZE;
    q.head = 0;
    q.tail = 0;
}

void Show_the_front_num_people(Queue &q, int num) {
    for (int i = 1; i <= num; ++i) {
        printf(" %d", q.data[q.head]);
        q.head = (q.head + 1) % q.size;
    }
    printf("\n");
}

void Let_people_into_the_Queue(Queue &q, int num) {
    int tail = (q.tail + 1) % q.size;
    if (tail == q.head) {
        realloc(q.data, q.size + INCRSIZE);
        q.size += INCRSIZE;
    }
    for (int i = 0; i < num; ++i) {
        int temp;
        input(temp);
        q.data[q.tail] = temp;
        q.tail = (q.tail + 1) % q.size;
    }
}

void Clear_Queue(Queue &q) {
    q.head = q.tail;
    delete []q.data;
}

int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    int T, cases = 1;
    scanf("%d", &T);
    while (T--) {
        printf("Case #%d :\n", cases++);
        int n, k;//n是事件的数量，k是最初有k个礼品
        Queue Q;
        Init_Queue(Q);
        input(n);
        input(k);
        for (int i = 0; i < n; ++i) {
            int m;
            input(m);
            int num_of_wait_people = (Q.tail - Q.head + Q.size) % Q.size;
            if (m == 0) {
                if (k < num_of_wait_people) {
                    printf("%d", k);
                    Show_the_front_num_people(Q, k);
                    k = 0;
                } else {
                    printf("%d", num_of_wait_people);
                    Show_the_front_num_people(Q, num_of_wait_people);
                    k -= num_of_wait_people;
                }
            } else if (m > 0) {
                Let_people_into_the_Queue(Q, m);
            } else if (m < 0) {
                k += (-m);
            }
        }
        Clear_Queue(Q);
    }
    return 0;
}