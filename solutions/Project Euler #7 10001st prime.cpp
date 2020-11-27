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
    
    vector<int> primes;
    for (int i = 2; i <= 1e6; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", primes[n - 1]);
    }   
	
    return 0;
}
