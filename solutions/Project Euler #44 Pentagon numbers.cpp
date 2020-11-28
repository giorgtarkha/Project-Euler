#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    
    long long pentagonals[1000001];
    set<long long> s_pentagonals;
    for (long long i = 1; i <= 1000000; i++) {
        pentagonals[i] = i * (3 * i - 1) / 2;
        s_pentagonals.insert(pentagonals[i]);
    }
    
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = k + 1; i < n; i++) {
        long long P1 = pentagonals[i], P2 = pentagonals[i - k];
        if (s_pentagonals.count(P1 - P2) || s_pentagonals.count(P1 + P2)) {
            printf("%lld\n", P1);
        }
    }
    
    return 0;
}
