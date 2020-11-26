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
        int n, k;
        scanf("%d %d", &n, &k);
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 0; i < n - k + 1; i++) {
            int prod = 1;
            for (int j = 0; j < k; j++) {
                prod *= s[i + j] - '0';
            }
            ans = max(ans, prod);
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
