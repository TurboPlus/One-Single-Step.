#include <bits/stdc++.h>
using namespace std;

struct queue_ {
    int data[1000];
    int head;
    int tail;
};

struct stack_ {
    int data[10];
    int top;
};
int main() {
    struct queue_ q1, q2;
    struct stack_ s;

    q1.data[1] = 2;
    q1.data[2] = 4;
    q1.data[3] = 1;
    q1.data[4] = 2;
    q1.data[5] = 5;
    q1.data[6] = 6;  

    q2.data[1] = 3;
    q2.data[2] = 1;
    q2.data[3] = 3;
    q2.data[4] = 5;
    q2.data[5] = 6;
    q2.data[6] = 4; 

    int book[10];
    int i, t;

    q1.head = 1; q1.tail = 7;
    q2.head = 1; q2.tail = 7;
    s.top = 0;

    for(i = 1; i <= 9; ++i) {
        book[i] = 0;
    }
    
    while(q1.head < q1.tail && q2.head < q2.tail) {
        std::cout << "q1: ";
        for(i=q1.head; i<q1.tail; ++i) {
            std::cout << q1.data[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "q2: ";
        for(i=q2.head; i<q2.tail; ++i) {
            std::cout << q2.data[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "cards: ";
        for(i = 1; i<=s.top; ++i) {
            std::cout << s.data[i] << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;

        t = q1.data[q1.head++];
        if(book[t] == 0) {
            s.top++;
            s.data[s.top] = t;
            book[t] = 1;
        } else {
            q1.data[q1.tail++] = t;
            while(s.data[s.top] != t) {
                book[s.data[s.top]] = 0;
                q1.data[q1.tail++] = s.data[s.top--];
            }
            q1.data[q1.tail++] = t;
            book[t] = 0;
            s.top--;
        }

        t = q2.data[q2.head++];
        if(book[t] == 0) {
            s.top++;
            s.data[s.top] = t;
            book[t] = 1;
        } else {
            q2.data[q2.tail++] = t;
            while(s.data[s.top] != t) {
                book[s.data[s.top]] = 0;
                q2.data[q2.tail++] = s.data[s.top--];
            }
            q2.data[q2.tail++] = t;
            book[t] = 0;
            s.top--;
        }
    }

    if(q2.tail == q2.head) {
        printf("q1 win : ");
        for(i=q1.head; i<q1.tail-1; ++i) {
            std::cout << q1.data[i] << " ";
        }
        std::cout << std::endl;
        if(s.top > 0) {
            std::cout << "cards on desk : ";
            for(i = 1; i<=s.top; ++i) {
                std::cout << s.data[i] << " ";
            }
            std::cout << std::endl;
        }
    } else {
        printf("q2 win : ");
    }

    return 0;
}