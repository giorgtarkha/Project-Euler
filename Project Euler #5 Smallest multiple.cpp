#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    int t;  
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int ans = n;  
        while (true) {  
            int k = 0;
            for(int i = 1; i <= n; i++) {
                if (ans % i == 0) {
                    k++;
                }
            }    
            if(k == n) { 
                break; 
            } 
            ans++;    
        }
        printf("%d\n", ans);
    }
	
    return 0;
}