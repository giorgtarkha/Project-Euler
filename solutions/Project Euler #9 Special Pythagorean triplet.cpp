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
        int n;
        scanf("%d", &n);
        long long ans = -1;
        for(long long a = 1; a < n; a++){
            long long b = (n * n - 2 * n * a) / (2 * n - 2 * a);
            long long c = n - a - b;
            if(a * a + b * b == c * c && a && b){
                ans = max(ans, a * b * c);
            }
        }    
        printf("%d\n", ans);
    }   
       
    return 0;
}
