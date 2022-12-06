#include <stdio.h>

struct node {
    int x;
    int y;
    int f;
    int s;
};

int main() {
    struct node que[2501];
    int book[51][51] = {0};
    int next[4][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };
    int head, tail;
    int i, j, k, p, q, tx, ty, flag;
    int n = 5, m = 4;
    int startX = 0, startY = 0; 
    int targetX = 3, targetY = 2;
    int result;
    int a[5][5] = {
        {0, 0, 1, 0}, 
        {0, 0, 0, 0},
        {0, 0, 1, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 1}
    };
    head = 1;
    tail = 1;
    que[tail].x = startX;
    que[tail].y = startY;
    que[tail].f = 0;
    que[tail].s = 0;
    tail++;
    book[startX][startY] = 1;
    flag = 0;
    while(head < tail) {
        for(k=0; k<4; ++k) {
            tx = que[head].x + next[k][0];
            ty = que[head].y + next[k][1];
            if(tx < 0 || tx >= n || ty < 0 || ty >= m) {
                continue;
            }
            if(a[tx][ty] == 0 && book[tx][ty] == 0) {
                book[tx][ty] = 1;
                que[tail].x = tx;
                que[tail].y = ty;
                que[tail].f = head;
                que[tail].s = que[head].s + 1;
                tail++;
            }
            if(tx == targetX && ty == targetY) {
                flag = 1;
                break;
            }
        }
        if(flag == 1) {
            break;
        }
        head++;
    }
    printf("%d\n", que[--tail].s);

    while(que[tail].f != 0) {
        printf("(%d, %d) <- ", que[tail].x, que[tail].y);
        tail = que[tail].f;
    }
    printf("(0, 0)");

    return 0;
}