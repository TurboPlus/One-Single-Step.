#include <stdio.h>

int n = 5, m = 4, flag = 0;
int a[51][51] = {
    {5, 3, 5, 3},
    {1, 5, 3, 0},
    {2, 3, 5, 1},
    {6, 1, 1, 5},
    {1, 5, 5, 4}
};
int book[51][51] = {0};

void dfs(int x, int y, int front) {
    if(x == n - 1 && y == m) {
        flag = 1;
        return;
    }
    if(x < 0 || x >=n || y < 0 || y >= m) {
        return;
    }
    if(book[x][y] == 1) {
        return;
    }
    book[x][y] = 1;
    if(a[x][y] == 5 || a[x][y] == 6) {
        if(front == 1) {
            dfs(x, y + 1, 1);
        }
        if(front == 2) {
            dfs(x + 1, y, 2);
        }
        if(front == 3) {
            dfs(x, y - 1, 3);
        }
        if(front == 4) {
            dfs(x - 1, y, 4);
        }
    }
    if(a[x][y] == 1 || a[x][y] == 2 || a[x][y] == 3 || a[x][y] == 4) {
        if(front == 1) {
            dfs(x + 1, y, 2);
            dfs(x - 1, y, 4);
        }
        if(front == 2) {
            dfs(x, y + 1, 1);
            dfs(x, y - 1, 3);
        }
        if(front == 3) {
            dfs(x + 1, y, 2);
            dfs(x - 1, y, 4);
        }
        if(front == 4) {
            dfs(x, y + 1, 1);
            dfs(x, y - 1, 3);  
        }
    }
    book[x][y] = 0;
    return;
}

int main() {
    dfs(0, 0, 1);
    if(flag == 1) {
        printf("success");
    } else {
        printf("fail");
    }
    return 0;
}