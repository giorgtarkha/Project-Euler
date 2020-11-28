#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

void go(vector<int>& v, int curr, int n, set<int>& s, int maxn) {
    if (!n) {
        v.push_back(curr);
        return;
    }
    for (int i = 1; i <= maxn; i++) {
        if (!s.count(i)) {
            s.insert(i);
            go(v, curr * 10 + i, n - 1, s, maxn);
            s.erase(i);
        }
    }    
}

bool prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    
    vector<int> sd;
    vector<int> fd;
    set<int> s;
    go(sd, 0, 7, s, 7);
    s.clear();
    go(fd, 0, 4, s, 4);
    
    vector<int> pprimes;
    
    for (int i = 0; i < fd.size(); i++) {
        if (prime(fd[i])) {
            pprimes.push_back(fd[i]);
        }
    }
    
    for (int i = 0; i < sd.size(); i++) {
        if (prime(sd[i])) {
            pprimes.push_back(sd[i]);
        }
    }
    
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int index = lower_bound(pprimes.begin(), pprimes.end(), n) - pprimes.begin(); 
        if (pprimes[index] == n) {
            printf("%d\n", n);
        } else if (index) {
            printf("%d\n", pprimes[index - 1]);
        } else {
            printf("-1\n");
        }
    }
      
    return 0;
}
