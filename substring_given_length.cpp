/**
 * author: marcavenzaid
 * created: 2018-08-03-01.05
 */

#include <bits/stdc++.h>

using namespace std;

void substr_given_length(string s, int n, int k) {
    for (int i = 0; i <= n-k; ++i) {
        cout << s.substr(i, k) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s = "abcdefg";
    substr_given_length(s, s.length(), 3);
    return 0;
}
