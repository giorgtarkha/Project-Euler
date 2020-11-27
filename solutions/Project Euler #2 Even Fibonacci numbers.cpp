#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	
	vector<long long> even_fib {2, 8};
    do {
        even_fib.push_back(4 * even_fib.back() + even_fib[even_fib.size() - 2]);
    } while (even_fib.back() < (2ll << 56));
    
    int t;
    scanf("%d", &t);
    while (t--) {
        long long n;
        scanf("%lld", &n);    
        long long ans = 0;
        int index = 0;
        while (even_fib[index] <= n) {
            ans += even_fib[index++];
        }
        printf("%lld\n", ans);
    }
    
    return 0;
}
