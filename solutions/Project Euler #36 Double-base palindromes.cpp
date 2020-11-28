#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_palindrome(string s) {
    for (int i = 0; i < s.length() / 2; i++) {
        if (s[i] != s[s.length() - i - 1]) {
            return false;
        }
    }
    return true;
}

string to_base_k(int n, int k) {
    string res = "";
    while (n) {
        int digit = n % k;
        res += digit;
        n /= k;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    
    int n, k;
    scanf("%d %d", &n, &k);  
    int ans = 0; 
    for (int i = 0; i < n; i++) {
        if (is_palindrome(to_string(i)) && is_palindrome(to_base_k(i, k))) {
            ans += i;
        }
    }
    
    printf("%d\n", ans);
     
    return 0;
}
