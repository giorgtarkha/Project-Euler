#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    int t1, t2, t3, k;
    scanf("%d %d %d %d", &t1, &t2, &t3, &k);
    
    int mod = 1;    
    int non_divisor_count = 0;
    while (non_divisor_count < k) {
        mod += 2;
        int tc1 = t1 % mod, tc2 = t2 % mod, tc3 = t3 % mod;
        int i1 = tc1, i2 = tc2, i3 = tc3;
        bool good = true;
        for (int i = 0; i <= 80000; i++) {
            int next = (tc1 + tc2 + tc3) % mod;
            if (next == 0) {
                good = false;
                break;
            }
            tc1 = tc2;
            tc2 = tc3;
            tc3 = next;
            if (tc1 == i1 && tc2 == i2 && tc3 == i3) {
                break;
            }
        }
        if (good) {
            non_divisor_count++;
        }
    }
    
    printf("%d\n", mod);
    
    return 0;
}
