#include <stdio.h>

int book[6], sum = 0, n = 5, e[6][6];

void dfs(int cur) {
    printf("%d ", cur);
    sum++;
    if(sum == n) {
        return;
    }
    for(int i=1; i<=n; ++i) {
        if(book[i] == 0 && e[cur][i] == 1) {
            book[i] = 1;
            dfs(i);
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
                e[i][j] = 999999999;
            }
        }
    }
    e[1][2] = 1;
    e[2][1] = 1;

    e[1][3] = 1;
    e[3][1] = 1;

    e[1][5] = 1;
    e[5][1] = 1;

    e[2][4] = 1;
    e[4][2] = 1;

    e[3][5] = 1;
    e[5][3] = 1;

    book[1] = 1;
    dfs(1);

    return 0;
}