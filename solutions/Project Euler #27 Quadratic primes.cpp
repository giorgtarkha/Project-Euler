#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int get_count(bool* is_prime, int a, int b) {
    int n = 0;
    while (true) {
        int curr = n * n + a * n + b;
        if (curr < 0 || !is_prime[curr]) {
            break;
        }
        n++;
    }
    return n;
}

int main() {
    
    bool is_prime[10000001];
    fill_n(is_prime, 10000000, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i * i <= 10000000; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= 10000000; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    vector<int> primes;
    for (int i = 2; i <= 2000; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    
    int n;
    scanf("%d", &n);
     
    pair<int, int> ans;
    int maxl = 0; 
    for (int i = 0; i < primes.size() && primes[i] <= n; i++) {
        for (int j = -n; j <= n; j++) {
            if (j % 2) {
                int curr = get_count(is_prime, j, primes[i]);
                if (curr > maxl) {
                    maxl = curr;
                    ans.first = j;
                    ans.second = primes[i];
                }
            }
        }
    } 
    
    printf("%d %d\n", ans.first, ans.second);
     
    return 0;
}
