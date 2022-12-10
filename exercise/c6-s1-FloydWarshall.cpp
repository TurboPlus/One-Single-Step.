/* 
question: 求任意两个点之间的最短距离
 - 最短路径算法 - Floyd-Warshall
 - 时间复杂度：O(N^3)
 - 不能解决带有“负权环”的图（因为每绕一次负权环，最短路径就减少1）
*/
#include <stdio.h>
int n = 4;
int e[4][4] = {
    0, 2, 6, 4,
    999, 0, 3, 999,
    7, 999, 0, 1,
    5, 999, 12, 0
};
int main() {
    for(int i=0; i<n; ++i) { // 只允许经过1号顶点、只允许经过1号顶点和2号顶点等等
        for(int j=0; j<n; ++j) {
            for(int k=0; k<n; ++k) {
                if(e[j][k] > e[j][i] + e[i][k]) {
                    e[j][k] = e[j][i] + e[i][k];
                }
            }
        }
    }

    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            printf("%d ", e[i][j]);
        }
        printf("\n");
    }
    return 0;
}