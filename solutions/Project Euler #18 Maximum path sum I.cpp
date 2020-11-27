#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                int x;
                scanf("%d", &x);
                dp[i].push_back(x);
            }
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < dp[i].size(); j++) {
                int left = 0, right = 0;
                if (j) {
                    left = dp[i - 1][j - 1];
                }
                if (j < dp[i].size() - 1) {
                    right = dp[i - 1][j];
                }
                dp[i][j] = max(left, right) + dp[i][j];
            }
        }
        
        int ans = dp[n - 1][0];
        for (int i = 1; i < dp[n - 1].size(); i++) {
            ans = max(ans, dp[n - 1][i]);
        }
        
        printf("%d\n", ans);
    }
      
    return 0;
}
