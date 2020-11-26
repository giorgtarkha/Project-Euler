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
        long long n;
        scanf("%lld", &n);
        long long ans = 2;
        for (long long prime = 2; prime * prime <= n; prime++) {
            while (n % prime == 0) {
                n /= prime;
                ans = prime;
            }
        }
        ans = max(ans, n);
        printf("%lld\n", ans);
    }
    
    return 0;
}
