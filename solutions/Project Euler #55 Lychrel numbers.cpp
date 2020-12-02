#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

bool is_palindrome(unsigned long long n) {
    string s = to_string(n);
    for (int i = 0; i < s.length() / 2; i++) {
        if (s[i] != s[s.length() - i - 1]) {
            return false;
        }
    }
    return true;
}

unsigned long long reverse(unsigned long long num) {
    unsigned long long reverse = 0;
    while (num) {
        unsigned long long remainder = num % 10;
        reverse = (reverse * 10) + remainder;
        num = num / 10;
    }
    return reverse;
}

int main() {
    
    int n;
    scanf("%d", &n);
    
    map<unsigned long long, int> count;
    for (int i = 1; i <= n; i++) {
        unsigned long long curr = i;
        for (int j = 0; j < 60; j++) {
            if (is_palindrome(curr)) {
                count[curr]++;
                break;
            }
            curr += reverse(curr);
        }
    }
    
    pair<unsigned long long, int> ans = {1, 1};
    for (auto it = count.begin(); it != count.end(); ++it) {
        if (it->second > ans.second) {
            ans = {it->first, it->second};
        }
    }
    
    printf("%llu %d\n", ans.first, ans.second);
    
    return 0;
}
