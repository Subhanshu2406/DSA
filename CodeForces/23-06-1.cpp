#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

void solve() {
    int a, x, y;
    cin >> a >> x >> y;

    if ((x < a && a < y) || (y < a && a < x))
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main() {
    fast_io
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
