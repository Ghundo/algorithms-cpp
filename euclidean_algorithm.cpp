/* Euclidean Algorithm: Algorithm for computing the GCD (greatest common
 * divisor) of two numbers (largest number that divides the two numbers without
 * leaving a remainder).
 *
 * Time complexity: O(log min(a, b))
 */

/**
 * author: marcavenzaid
 * created: 2018-09-05-20.55
 */

#include <bits/stdc++.h>

using namespace std;

int euclidean_algorithm(int a, int b) {
    if (a == 0) {
        return b;
    }
    euclidean_algorithm(b % a, a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a = 24;
    int b = 16;
    cout << euclidean_algorithm(a, b);
    return 0;
}
