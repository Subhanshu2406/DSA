// fixed solution following the editorial logic
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; cin >> n;
        map<ll,int> cnt;
        for (int i = 0; i < n; ++i) {
            ll x; cin >> x;
            cnt[x]++;
        }

        ll base = 0;                // sum of one from each pair: sum x * (cnt[x] / 2)
        vector<ll> odd;             // lengths with odd count (one leftover)
        vector<ll> even_with_pairs; // lengths with even count >= 2 (contribute to base but no leftover)

        for (auto &p : cnt) {
            ll x = p.first;
            int c = p.second;
            base += x * (c / 2);
            if (c % 2 == 1) odd.push_back(x);
            else if (c >= 2) even_with_pairs.push_back(x);
        }

        if (base == 0) { // no pairs at all -> impossible to form required symmetric polygon
            cout << 0 << '\n';
            continue;
        }

        ll ans = 0;

        // Case: use exactly one odd (stick crossing the symmetry line)
        // Condition from editorial: 2*base > x
        for (ll x : odd) {
            if (2 * base > x) ans = max(ans, 2 * base + x);
        }

        // Case: use exactly two odd sticks (they must be chosen as adjacent in sorted leftover list)
        sort(odd.begin(), odd.end());
        for (int i = 1; i < (int)odd.size(); ++i) {
            ll small = odd[i-1], large = odd[i];
            // editorial condition: small + 2*base > large
            if (small + 2 * base > large) {
                ans = max(ans, small + 2 * base + large);
            }
        }

        // Case: maybe we can keep using only pairs (perimeter = 2*base).
        // Editorial checks even_with_pairs: if there exists a length x with even count >=2 such that base - x > 0,
        // then 2*base is a valid perimeter (we can remove one pair of that length and use the two sticks intersecting line).
        // Equivalent interpretation from editorial code:
        for (ll x : even_with_pairs) {
            if (base - x > 0) {
                ans = max(ans, 2 * base);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
