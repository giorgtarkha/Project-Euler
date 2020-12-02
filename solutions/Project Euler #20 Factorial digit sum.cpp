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
        vector<int> digits{1};
        for (int i = 1; i <= n; i++) {
            int carry = 0;
            int prod = 1;
            for (int j = digits.size() - 1; j >= 0; j--) {
                prod = digits[j] * i + carry;
                digits[j] = prod % 10;
                carry = prod / 10;
            }
            while (carry) {
                digits.insert(digits.begin(), carry % 10);
                carry /= 10;
            }
        }
        int ans = 0;
        for (int i = 0; i < digits.size(); i++) {
            ans += digits[i];
        }
        printf("%d\n", ans);  
    }  
    return 0;
}
