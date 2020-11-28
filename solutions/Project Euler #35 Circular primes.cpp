#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

bool is_cercular(int n, int* primes) {
    string s = to_string(n);
    string initial = s;
    while (true) {
        s = s.substr(1, s.length() - 1) + s.substr(0, 1);
        if (s[0] == '0' || !primes[stoi(s)]) {
            return false;
        }
        if (s == initial) {
            break;
        }
    }
    return true;
}

int main() {
    
    int is_prime[1000001];
    fill_n(is_prime, 1000000, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i * i <= 1000000; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= 1000000; j += i) {
                is_prime[j] = false;    
            }
        }
    }
    
    int n;
    scanf("%d", &n);
    int ans = 0;
;    for (int i = 2; i < n; i++) {
        if (is_prime[i]) {
            if (is_cercular(i, is_prime)) {
                ans += i;
            }
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}
