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
    int n,x,y;
    cin >> n >> x >> y;
    vector<int> arr(n);
    for(int i = 0; i < n ; i++){
        cin >> arr[i];
    }
    unordered_map<int,int> first;
    unordered_map<int,int> second;
    int res = 0;

    for(int i = 0 ;i <n;i++){
        first[arr[i]%x]++;
        second[arr[i]%y]++;
    }

    for(int i = 0; i < n; i++){
        int modX = arr[i] % x;
        int modY = arr[i] % y;

        first[modX]--;
        second[modY]--;

        if (first[modX] > 0 && second[(y - modY) % y] > 0) {
            res++;
        }
    }

    cout << res << '\n';
    return;
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