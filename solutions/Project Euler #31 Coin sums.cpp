#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MOD 1000000007

int coins[] = { 1, 2, 5, 10, 20, 50, 100, 200 };

int main() {
    
    long long dp[100001] = {0};
    dp[0] = 1;
    for (int j = 0; j < 8; j++) {
        for (int i = 1; i <= 100000; i++) {
            if (coins[j] <= i) {
                dp[i] += dp[i - coins[j]];
                dp[i] %= MOD;
            }
        }
    }
       
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%lld\n", dp[n]);
    }   
       
    return 0;
}
