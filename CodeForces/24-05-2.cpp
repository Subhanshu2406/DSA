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

void solve() {
    int n;
    cin >> n;
    vector<int> arr1(n), arr2(n);
    vector<long long> arr3(n);
 
    for (int i = 0; i < n; i++) cin >> arr1[i];
    for (int i = 0; i < n; i++) cin >> arr2[i];
 
    for (int i = 0; i < n; i++) {
        arr2[i] = 1LL << arr2[i];
        arr1[i] = 1LL << arr1[i];
    }
    
    for (int i = 0; i < n; i++) {
        long long temp = 0;
        for (int j = 0; j <= i; j++) {
            long long t1 = arr1[j];
            long long t2 = arr2[i - j];
            long long t = t1 + t2;
            if (t > temp) temp = t;
        }
        arr3[i] = temp % 998244353;
    }
 
    for (int i = 0; i < n; i++) cout << arr3[i] << " ";
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
