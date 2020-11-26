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
        long long n;
        scanf("%lld", &n);
        n--;
        long long sum3 = (3 + n - n % 3) * (n - n % 3) / 6,
                  sum5 = (5 + n - n % 5) * (n - n % 5) / 10,
                  sum15 = (15 + n - n % 15) * (n - n % 15) / 30;
        printf("%lld\n", sum3 + sum5 - sum15);
    }
	
    return 0;
}
