#include <stdio.h>

int book[6] = {0}, n = 5, e[6][6];
int result = 999999999, target = 5;

void dfs(int cur, int dis) {
    if(dis > result) {
        return;
    }
    if(cur == target) {
        if(dis < result) {
            result = dis;
        }
        return;
    }
    for(int i=1; i<=n; ++i) {
        if(book[i] == 0 && e[cur][i] != 999999) {
            book[i] = 1;
            dfs(i, dis + e[cur][i]);
            book[i] = 0;
        }
    }
    return;
}

int main() {
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            if(i == j) {
                e[i][j] = 0;
            } else {
                e[i][j] = 999999;
            }
        }
    }

    e[1][2] = 2;
    e[1][5] = 10;
    e[2][3] = 3;
    e[2][5] = 7;
    e[3][1] = 4;
    e[3][4] = 4;
    e[4][5] = 5;
    e[5][3] = 3;

    book[1] = 1;
    dfs(1, 0);
    printf("%d", result);
    return 0;
}