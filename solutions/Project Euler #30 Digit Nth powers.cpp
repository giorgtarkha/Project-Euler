#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool good(int num, int n) {
    int sum = 0;
    int initial = num;
    while (num) {
        int d = num % 10;
        sum += pow(d, n);
        num /= 10;
    }
    return sum == initial;
}

int main() {
    
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 10; i <= 1000000; i++) {
        if (good(i, n)) {
            sum += i;
        }
    }
    printf("%d\n", sum); 
     
    return 0;
}
