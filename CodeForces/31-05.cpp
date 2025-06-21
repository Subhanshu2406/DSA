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
    vector<int> vec(n);
    for(int i = 0 ; i< n ; i++){
        cin >>vec[i];
    }

    sort(vec.begin(),vec.end());

    for(int i = 0 ;i < n;i++){
        if(vec[i] % 2 == 0) vec[i] = 1;
        else vec[i] = 0;
    }

    int l = 0;
    int r = vec.size() - 1;

    int odd = 0;
    int even = 0;

    while(l<=r){
        if(vec[l] == 0 && vec[r] == 0) break;
        if(vec[l] != 0){
            odd++;
            l++;
        }

        if(vec[r] != 0){
            odd++;
            r--;
        }
    }

    l = 0;
    r = vec.size() -1;

    while(l<=r){
        if(vec[l] == 1 && vec[r] == 1) break;
        if(vec[l] != 1){
            even++;
            l++;
        }

        if(vec[r] != 1){
            even++;
            r--;
        }
    }

    if(even > odd) cout << odd;
    else cout << even;
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
