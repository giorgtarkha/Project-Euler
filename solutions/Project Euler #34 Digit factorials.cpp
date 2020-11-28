#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool good(int n, vector<int>& facts) {
    int initial = n;
    int sum = 0;
    while (n) {
        sum += facts[n % 10];
        n /= 10;
    }
    return sum % initial == 0;
}

int main() {
    
    vector<int> facts {1};
    for (int i = 1; i <= 9; i++) {
        facts.push_back(facts.back() * i);
    }
    
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 10; i < n; i++) {
        if (good(i, facts)) {
            ans += i;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}
