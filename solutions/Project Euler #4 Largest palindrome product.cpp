#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_palindrome(int n) {
    string s = to_string(n);
    for (int i = 0; i < s.length() / 2; i++) {
        if (s[i] != s[s.length() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    
    vector<int> palindromes;
    for (int i = 100; i <= 999; i++) {
        for (int j = i; j <= 999; j++) {
            if (is_palindrome(i * j)) {
                palindromes.push_back(i * j);
            }
        }
    }
    
    sort(palindromes.begin(), palindromes.end());
    
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int ans = 101110;
        for (int i = 0; i < palindromes.size(); i++) {
            if (palindromes[i] < n) {
                ans = palindromes[i];
            }
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}
