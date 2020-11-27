#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    int n;
    scanf("%d", &n);
    vector<string> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
      
    int index = 49;
    int remainder = 0;
    string result = "";
    while (index >= 0) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i][index] - '0';
        }
        sum += remainder;
        result = to_string(sum % 10) + result;
        remainder = sum / 10;
        index--;
    }  
    
    result = to_string(remainder) + result;
    printf("%.10s\n", result.c_str());
      
    return 0;
}
