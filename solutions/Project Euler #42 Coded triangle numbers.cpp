#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        long long tn;
        scanf("%lld", &tn);
        long long D = 1 + 8 * tn;
        long long sq = sqrt(D);
        if (sq * sq == D && (sq - 1) % 2 == 0) {
            printf("%lld\n", (sq - 1) / 2);
        } else {
            printf("-1\n");
        }
    }
      
    return 0;
}
