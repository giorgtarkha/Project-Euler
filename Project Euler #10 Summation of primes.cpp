#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    bool is_prime[1000001];
    fill_n(is_prime, 1e6, true);
    for (int i = 2; i * i <= 1e6; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= 1e6; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    vector<long long> primes;
    for (int i = 2; i <= 1e6; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    
    vector<long long> primes_sum {primes[0]}; 
    for (int i = 1; i < (int) primes.size(); i++) {
        primes_sum.push_back(primes_sum[i - 1] + primes[i]);
    }
    
    int t;
    scanf("%d", &t);
    while (t--) {
        long long n; 
        scanf("%lld", &n);
        int index = lower_bound(primes.begin(), primes.end(), n) - primes.begin();
        if (primes[index] != n) {
            index--;
        }
        printf("%lld\n", index == -1 ? 0 : primes_sum[index]);
    }
    
    return 0;
}
