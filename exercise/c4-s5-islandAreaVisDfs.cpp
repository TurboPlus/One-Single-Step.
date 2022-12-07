#include <stdio.h>

struct node {
    int x;
    int y;
};

int a[51][51] = {
    {1, 2, 1, 0, 0, 0, 0, 0, 2, 3},
    {3, 0, 2, 0, 1, 2, 1, 0, 1, 2},
    {4, 0, 1, 0, 1, 2, 3, 2, 0, 1},
    {3, 2, 0, 0, 0, 1, 2, 4, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 5, 3, 0},
    {0, 1, 2, 1, 0, 1, 5, 4, 3, 0},
    {0, 1, 2, 3, 1, 3, 6, 2, 1, 0},
    {0, 0, 3, 4, 8, 9, 7, 5, 0, 0},
    {0, 0, 0, 3, 7, 8, 6, 0, 1, 2},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int book[51][51];
int n = 10, m = 10;
int sum = 1;

void dfs(int x, int y, int color) {
    int next[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    a[x][y] = color;
    for(int k=0; k<4; ++k) {
        int tx = x + next[k][0];
        int ty = y + next[k][1];
        if(tx < 0 || tx >= n || ty < 0 || ty >= m) {
            continue;
        }
        if(a[tx][ty] > 0 && book[tx][ty] == 0) {
            ++sum;
            book[tx][ty] = 1;
            dfs(tx, ty, color);
        }
    }
    return;
}

int main() {
    int startX = 4, startY = 6;
    dfs(startX, startY, -1);
    printf("%d\n", sum);
    for(int i=0; i<10; ++i) {
        for(int j=0; j<10; ++j) {
            printf("%3d ", a[i][j]); // 宽度为3，左对齐
        }
        printf("\n");
    }
    return 0;
}