#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    long long sum_square[10001] = {0}, square_sum[10001] = {0};
    for (int i = 1; i <= 10000; i++) {
        sum_square[i] = sum_square[i - 1] + i;
        square_sum[i] = square_sum[i - 1] + i * i;
    }
    
    for (int i = 1; i <= 10000; i++) {
        sum_square[i] *= sum_square[i];
    }
    
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%lld\n", sum_square[n] - square_sum[n]);
    }
       
    return 0;
}
