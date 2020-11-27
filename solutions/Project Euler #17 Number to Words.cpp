#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string singles[] = {
    "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"
};

string tens[] = {
    "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
};

string tensm[] = {
    "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
};

string go(long long num, string ending) {
    bool non_zero = num;
    string ans = "";
    if (num >= 100) {
        ans += singles[num / 100 - 1] + " Hundred";
    }
    num %= 100;
    if (num >= 10 && num <= 19) {
        ans += " " + tens[num - 10];
    } else { 
        if (num >= 10) {
            ans += " " + tensm[num / 10 - 2];
        }
        num %= 10;
        if (num) {
            ans += " " + singles[num - 1];
        }   
    }

    if (non_zero) {
        ans += " " + ending;
    }    
    
    return ans;
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        long long n;
        scanf("%lld", &n);
        if (!n) {
            printf("Zero\n");
            continue;
        }
        
        vector<string> parts;
        parts.push_back(go(n / 1e12, "Trillion"));
        n %= 1000000000000;
        parts.push_back(go(n / 1e9, "Billion"));
        n %= 1000000000;
        parts.push_back(go(n / 1e6, "Million"));
        n %= 1000000;
        parts.push_back(go(n / 1e3, "Thousand"));
        n %= 1000;
        parts.push_back(go(n, ""));
        
        string ans = "";
        for (int i = 0; i < parts.size(); i++) {
            if (parts[i] == "") {
                continue;
            }
            ans += " " + parts[i];
        }

        while (ans.front() == ' ') {
            ans.erase(ans.begin());
        }
        
        while (ans.back() == ' ') {
            ans.pop_back();
        }
        
        string proper_ans = string(1, ans[0]);
        for (int i = 1; i < ans.length(); i++) {
            if (proper_ans.back() == ' ' && ans[i] == ' ') {
                continue;
            }
            proper_ans.push_back(ans[i]);
        }
        
        printf("%s\n", proper_ans.c_str());
    }
     
    return 0;
}
