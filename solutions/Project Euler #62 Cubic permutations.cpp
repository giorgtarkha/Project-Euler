#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int main() {
    
    int n, k;
    scanf("%d %d", &n, &k);
    vector<pair<string, unsigned long long>> permutations;
    for (unsigned long long i = 0; i < n; i++) {
        unsigned long long num = i * i * i;
        string curr = to_string(num);
        sort(curr.begin(), curr.end());
        permutations.push_back({curr, num});
    }
    
    sort(permutations.begin(), permutations.end());
    permutations.push_back({"", 0});
    int len = 1;
    unsigned long long curr_min = permutations[0].second;
    vector<unsigned long long> ans;
    for (int i = 1; i < permutations.size(); i++) {
        if (permutations[i].first != permutations[i - 1].first) {
            if (len == k) {
                ans.push_back(curr_min);
            }
            curr_min = permutations[i].second;
            len = 1;        
        } else {
            curr_min = min(curr_min, permutations[i - 1].second);
            len++;
        }
    }
    
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        printf("%llu\n", ans[i]);
    }
       
    return 0;
}
