#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    
    vector<set<int>> divisors(30000);
    for (int i = 0; i < 30000; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                divisors[i].insert(j);
                if (j > 1) {
                    divisors[i].insert(i / j);
                }
            }
        }
    }
    
    set<int> abundants;
    for (int i = 0; i < 30000; i++) {
        int sum = 0;
        for (auto it = divisors[i].begin(); it != divisors[i].end(); ++it) {
            sum += *it;
        }
        if (sum > i) {
            abundants.insert(i);
        }
    }
    
    bool can[30001] = {false};
    for (int i = 0; i < 30000; i++) {
        for (auto it = abundants.begin(); it != abundants.end(); ++it) {
            if (*it > i) {
                break;
            }
            if (abundants.count(i - *it)) {
                can[i] = true;
                break;
            }
        }    
    }
    
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        if (n > 28123) {
            printf("YES\n");
            continue;
        }
        printf(can[n] ? "YES\n" : "NO\n");
        
    }
    return 0;
}
