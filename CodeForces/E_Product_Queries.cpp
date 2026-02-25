//author : subhanshugupta2406
#include <bits/stdc++.h>
using namespace std;

// Fast I/O
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

// Shortcuts
#define ll long long
#define ull unsigned long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define Y cout<<"YES"
#define N cout<<"NO"
#define L cout<<"\n"
#define M cout<<-1
#define fr(i,n) for(int i=0;i<(n);i++)
#define mxe(x) *max_element(x.begin(),x.end())
#define mne(x) *min_element(x.begin(),x.end())

// Debug
#ifdef LOCAL
    #define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
    #define debug(x)
#endif

// Printing templates for debugging
template<typename T> void _print(T x) { cerr << x; }
template<typename T, typename V> void _print(pair<T, V> p) { cerr << "{"; _print(p.first); cerr << ", "; _print(p.second); cerr << "}"; }
template<typename T> void _print(vector<T> v) { cerr << "["; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }
template<typename T> void _print(set<T> s) { cerr << "{"; for (auto i : s) { _print(i); cerr << " "; } cerr << "}"; }

const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = LLONG_MAX;

int MAX;
vector<int> spf;


void build_spf() {
    for (int i = 1; i <= MAX; i++) spf[i] = i;
    for (int i = 2; i * i <= MAX; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAX; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

vector<int> get_factors(int x) {
    unordered_map<int,int> cnt;
    while (x > 1) {
        cnt[spf[x]]++;
        x /= spf[x];
    }
    vector<int> factors = {1};
    for (auto [p, e] : cnt) {
        int sz = factors.size();
        int cur = 1;
        for (int i = 1; i <= e; i++) {
            cur *= p;
            for (int j = 0; j < sz; j++) {
                factors.push_back(factors[j] * cur);
            }
        }
    }
    return factors;
}

void solve() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, INT_MAX);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        dp[x] = 1;
    }

    MAX = n;
    spf.resize(n + 1);
    build_spf();

    for (int i = 1; i <= n; i++) {
        auto factors = get_factors(i);
        for (int d : factors) {
            if (d == 1 || i/d == 1) continue;
            int other = i / d;
            if (dp[d] != INT_MAX && dp[other] != INT_MAX) {
                dp[i] = min(dp[i], dp[d] + dp[other]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dp[i] == INT_MAX) cout << -1 << " ";
        else cout << dp[i] << " ";
    }
    cout << "\n";
}

int main() {
    fast_io
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}