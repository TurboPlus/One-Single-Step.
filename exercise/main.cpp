#include <bits/stdc++.h>
using namespace std;

struct note {
    int x;
    int y;
    int f;
    int s;
};

int main() {
    std::cout << "main" << std::endl;
    struct note que[2501];
    int a[51][51] = {0}, book[51][51] = {0};
    int next[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int head, tail;
    int i, j, k, n, m, startx, starty, p, q, tx, ty, flag;
    
    head = 1;
    tail = 1;
    que[tail].x = startx;
    que[tail].y = starty;
    que[tail].f = 0;
    que[tail].s = 0;
    tail++;
    book[startx][starty] = 1;
    flag = 0;
    while(head < tail) {
        for(k=0; k<=3; ++k) {
            tx = que[head].x + next[k][0];
            ty = que[head].y + next[k][1];
            if(tx<1 || tx>n || ty<1 || ty>m) {
                continue;
            }
        }
    }


	return 0;
}