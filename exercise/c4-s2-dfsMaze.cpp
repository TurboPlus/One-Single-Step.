#include <stdio.h>
#include <iostream>
using namespace std;

int a[5][5] = {
    {0, 0, 1, 0}, 
    {0, 0, 0, 0},
    {0, 0, 1, 0},
    {0, 1, 0, 0},
    {0, 0, 0, 1}
};
int row = 5, col = 4, minStep = INT_MAX;
int startX = 0, startY = 0;
int targetX = 3, targetY = 2;
int book[5][5] = {0};

void dfs(int x, int y, int step) {
    int next[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    if(x == targetX && y == targetY) {
        minStep = min(step, minStep);
        return;
    }
    for(int i=0; i<4; ++i) {
        int tx = x + next[i][0];
        int ty = y + next[i][1];
        if(tx >= 0 && tx <= row-1 && ty >= 0 && ty <= col - 1) {
            if(a[tx][ty] == 0 && book[tx][ty] == 0) {
                book[tx][ty] = 1;
                dfs(tx, ty, step + 1);
                book[tx][ty] = 0;
            }
        }
    }
    return;
}

int main() {
    book[startX][startY] = 1;
    dfs(startX, startY, 0);
    cout << "The result is: " << minStep << endl;
    return 0;
}