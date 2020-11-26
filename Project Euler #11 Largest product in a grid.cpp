#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int grid[21][21];
int main() {
   
    for(int i = 1; i <= 20; i++) {
        for (int j = 1; j <= 20; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= 20; j++) {
            ans = max(ans, grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3]);    
            ans = max(ans, grid[i][j] * grid[i][j - 1] * grid[i][j - 2] * grid[i][j - 3]);    
            ans = max(ans, grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j]);
            ans = max(ans, grid[i][j] * grid[i - 1][j] * grid[i - 2][j] * grid[i - 3][j]);
            ans = max(ans, grid[i][j] * grid[i - 1][j + 1] * grid[i - 2][j + 2] * grid[i - 3][j + 3]);
            ans = max(ans, grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3] * grid[i][j]); 
            ans = max(ans, grid[i + 1][j - 1] * grid[i][j] * grid[i + 2][j - 2] * grid[i + 3][j - 3]);
            ans = max(ans, grid[i - 1][j - 1] * grid[i][j] * grid[i - 2][j - 2] * grid[i - 3][j - 3]);       
        }
    }
  
    printf("%d\n", ans);
      
    return 0;
}
