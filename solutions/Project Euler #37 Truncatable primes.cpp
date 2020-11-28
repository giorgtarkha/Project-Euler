#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_truncable_prime(int n, bool* primes) {
    string s = to_string(n);
    for (int i = 0; i < s.length(); i++) {
        string sub_left = s.substr(i, s.length() - i);
        string sub_right = s.substr(0, s.length() - i);
        if (sub_left[0] == '0' || sub_right[0] == '0' || !primes[stoi(sub_left)] || !primes[stoi(sub_right)]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    
    bool is_prime[1000001];
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
    for (int i = 11; i < n; i++) {
        if (is_prime[i] && is_truncable_prime(i, is_prime)) {
            ans += i;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}
