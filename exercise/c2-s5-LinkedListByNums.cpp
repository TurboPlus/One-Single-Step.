#include <stdio.h>

int main() {
    // 用数组模拟链表
    int data[100] = {0, 2, 3, 5, 8, 9, 10, 18,26, 32};
    int right[100]; // 
    int i, n = 9, t, pre_t, len = n;
    for(i = 1; i <= n; ++i) {
        if(i != n) {
            right[i] = i + 1;
        } else {
            right[i] = 0;
        }
    }

    len++;
    scanf("%d", &data[len]);
    t = 1;
    while(t != 0) {
        if(data[right[t]] > data[len]) {
            right[len] = right[t];
            right[t] = len;
            break; 
        }
        pre_t = t;
        t = right[t];
    }

    if(t == 0) {
        right[pre_t] = len;
        right[len] = 0;
    }

    t = 1;
    while(t != 0) {
        printf("%d ", data[t]);
        t = right[t];
    }

    return 0;
}