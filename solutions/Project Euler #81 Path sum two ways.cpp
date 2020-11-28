#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    int n;
    scanf("%d", &n);
    vector<vector<long long>> mat(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lld", &mat[i][j]);
        }
    }
    
    for (int i = 1; i < n; i++) {
        mat[0][i] += mat[0][i - 1];
        mat[i][0] += mat[i - 1][0];
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            mat[i][j] += min(mat[i - 1][j], mat[i][j - 1]);
        }
    }
    
    printf("%lld\n", mat[n - 1][n - 1]);
    
    return 0;
}
