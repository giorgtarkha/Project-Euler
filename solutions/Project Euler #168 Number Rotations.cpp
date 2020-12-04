#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string ten_pow_m_d(int n, int d) {
    return string(n - 1, '9') + string(1, '0' + 10 - d);
}

string mult_b_d(string& to_mult, int d) {
    string res = "";
    int remainder = 0;
    for (int i = to_mult.size() - 1; i >= 0; i--) {
        int mult = (to_mult[i] - '0') * d + remainder;
        res = string(1, '0' + mult % 10) + res;
        remainder = mult / 10;
    }
    if (remainder) {
        res = to_string(remainder) + res;
    }
    return res;
}

int mod(string& num, int dv) {
    int res = 0; 
    for (int i = 0; i < (int) num.length(); i++) {
        res = (res * 10 + num[i] - '0') % dv; 
    }
    return res; 
}

string divide(string number, int divisor) { 
    string res; 
    int index = 0; 
    int temp = number[index] - '0'; 
    while (temp < divisor) {
        temp = temp * 10 + (number[index + 1] - '0'); 
        index++;
    }
    while ((int) number.length() > index) { 
        res += (temp / divisor) + '0'; 
        temp = (temp % divisor) * 10 + number[index + 1] - '0'; 
        index++;
    } 
    if (res.length() == 0) {
        return "0"; 
    }
    return res; 
} 

int main() {
    
    int m;
    scanf("%d", &m);
    vector<string> all;
    for (int k = 2; k <= m; k++) {
        for (int b = 1; b <= 9; b++) {
            for (int x = 1; x <= 9; x++) {
                string tp = ten_pow_m_d(k - 1, x);     
                int dv = 10 * x - 1;
                tp = mult_b_d(tp, b);
                bool divisible = mod(tp, dv) == 0;
                if (divisible) {
                    string a = divide(tp, dv);
                    string res = a + to_string(b);
                    string check = mult_b_d(res, x);
                    if (check.length() != res.length()) {
                        continue;
                    }
                    reverse(res.begin(), res.end());
                    all.push_back(res);
                }
            }
        }            
    }
    
    string ans = "";
    int remainder = 0;
    for (int i = 0; i < 5; i++) {
        int sum = remainder;
        for (int j = 0; j < (int) all.size(); j++) {
            if (all[j].length()) {
                sum += all[j].front() - '0';
                all[j].erase(all[j].begin());
            }
        }
        ans += to_string(sum % 10);
        remainder = sum / 10;
    }
    ans += to_string(remainder);
    while (ans.back() == '0' || ans.size() > 5) {
        ans.pop_back();
    }
    
    reverse(ans.begin(), ans.end());  
    printf("%s\n", ans.c_str());  
      
    return 0;
}
