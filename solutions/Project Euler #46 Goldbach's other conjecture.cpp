#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    bool is_prime[500001];
    fill_n(is_prime, 500000, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i * i <= 500000; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= 500000; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (n - i * i * 2 < 0) {
                break;
            }
            ans += is_prime[n - i * i * 2];
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
