#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

bool good(int i, int j, int n) {
    int res = i * j;
    string s = to_string(i) + to_string(j) + to_string(res);
    if (s.length() != n) {
        return false;
    }
    sort(s.begin(), s.end());
    for (int i = 1; i <= s.length(); i++) {
        if (s[i - 1] - '0' != i) {
            return false;
        }
    }
    return true;
}

int main() {
    
    int n;
    scanf("%d", &n);
    set<int> numbers;
    for (int i = 0; i < 2000; i++) {
        for (int j = 0; j < 2000; j++) {
            if (good(i, j, n)) {
                numbers.insert(i * j);
            }
        }
    }
        
    int ans = 0;
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        ans += *it;
    }    
        
    printf("%d\n", ans);
        
    return 0;
}
