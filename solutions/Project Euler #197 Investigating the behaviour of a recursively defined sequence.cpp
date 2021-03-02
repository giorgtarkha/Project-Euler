#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

double f(double u, double b) {
    return pow(2, b - u * u) * 0.000000001;
}

int main() {
    double u0, b;
    scanf("%lf %lf", &u0, &b);
    double current_u = u0, previous_u;
    for (int i = 0; i <= 1000000; i++) {
        previous_u = current_u;
        current_u = f(current_u, b);
    }
    printf("%.9lf", current_u + previous_u);
    return 0;
}