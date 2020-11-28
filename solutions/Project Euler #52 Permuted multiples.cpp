#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool same_digits(int n1, int n2) {
    int count[10] = {0};
    while (n1) {
        count[n1 % 10]++;
        n1 /= 10;
    }
    
    while (n2) {
        count[n2 % 10]--;
        n2 /= 10;
    }
    
    for (int i = 0; i < 10; i++) {
        if (count[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        bool good = true;
        for (int j = 2; j <= k; j++) {
            if (!same_digits(i, i * j)) {
                good = false;
                break;
            }
        }
        if (good) {
            for (int j = 1; j <= k; j++) {
                printf("%d ", i * j);
            }
            printf("\n");
        }
    }
    
    return 0;
}
