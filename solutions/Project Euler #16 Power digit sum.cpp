#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long dup(string& curr) {
    int remainder = 0;
    long long ans = 0;
    for (int i = 0; i < (int) curr.length(); i++) {
        int d = curr[i] - '0';
        int sum = d * 2 + remainder;
        remainder = sum / 10;
        curr[i] = '0' + sum % 10;
        ans += curr[i] - '0';
    }
    if (remainder) {
        curr.push_back(remainder + '0');
        ans += curr.back() - '0';
    }
    return ans;
}

int main() {
    long long ans[10001] = {0};
    ans[1] = 2;
    string start = "2";
    for (int i = 2; i <= 10000; i++) {
        ans[i] = dup(start);       
    }
    
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%lld\n", ans[n]);
    }
      
    return 0;
}