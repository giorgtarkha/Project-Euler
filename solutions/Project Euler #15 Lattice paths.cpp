#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MOD 1000000007

long long power(long long x, int y) {
    long long res = 1;
    x %= MOD;
 
    while (y) { 
        if (y & 1) {
            res = (res * x) % MOD;
        }
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}
 
long long modInverse(long long n) {
    return power(n, MOD - 2);
}
 
long long NCR(long long n, int r) {
    if (n < r) {
        return 0;
    }
    if (r == 0) {
        return 1;
    }
 
    long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }
 
    return (fac[n] * modInverse(fac[r]) % MOD * modInverse(fac[n - r]) % MOD) % MOD;
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        printf("%lld\n", NCR(n + m, n));
    }
    
    return 0;
}
