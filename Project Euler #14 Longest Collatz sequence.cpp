#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

void go(long long n, vector<int>& memo) {
    int ans = 0;
    int start = n;
    while (n != 1) {
        if (n <= 5000000 && memo[n]) {
            ans += memo[n];
            break;
        }
        if (n % 2) {
            n = 3 * n + 1;
            ans++;
        } else {
            n /= 2;
            ans++;
        }
    }
    memo[start] = ans;
    
}

int main() {
    
    vector<int> memo(5000001, 0);
    memo[1] = 1;
    for (long long i = 1; i <= 5000000; i++) {
        if (!memo[i]) {
            go(i, memo);
        }
    }
    
    int ans[5000001];
    ans[1] = 1;
    for (int i = 2; i <= 5000000; i++) {
        if (memo[ans[i - 1]] <= memo[i]) {
            ans[i] = i;
        } else {
            ans[i] = ans[i - 1];
        }
    }
    
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
     
    return 0;
}
