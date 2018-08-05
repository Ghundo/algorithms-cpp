/**
 * author: marcavenzaid
 * created: 2018-07-14-18.18
 */

#include <bits/stdc++.h>

using namespace std;

int cmodp_dp(int n, int r, int p) {
    int C[r+1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = min(i, r); j > 0; --j) {
            C[j] = (C[j] + C[j-1])%p;
        }
    }
    return C[r];
}

int cmodp_lucas(int n, int r, int p) {
    if (r==0) {
        return 1;
    }
    int ni = n%p, ri = r%p;
    return (cmodp_lucas(n/p, r/p, p) * cmodp_dp(ni, ri, p)) % p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << cmodp_lucas(10, 2, 13);
    return 0;
}
