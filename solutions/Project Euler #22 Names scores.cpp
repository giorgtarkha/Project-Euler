#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    
    int n;
    scanf("%d", &n);
    vector<string> names(n);
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }
    
    sort(names.begin(), names.end());
    map<string, int> scores;
    for (int i = 0; i < names.size(); i++) {
        int score = 0;
        for (int j = 0; j < names[i].length(); j++) {
            score += names[i][j] - 'A' + 1;
        }
        score *= (i + 1);
        scores[names[i]] = score;
    }
    
    int q;
    scanf("%d", &q);
    while (q--) {
        string name;
        cin >> name;
        printf("%d\n", scores[name]);
    }
    
    return 0;
    
}
