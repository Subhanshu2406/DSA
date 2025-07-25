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
    vector<pair<int,int>> sorted(n);

    for(int i = 0 ;i < n ; i++){
        cin >> vec[i];
        sorted[i] = {vec[i], i}; 
    }

    if(n == 1){
        cout << -1;
        cout << "\n";
        return;
    }

    if(n == 2){
        if(abs(vec[0] - vec[1]) <= 1) cout << 0;
        else cout<< -1;
        cout << "\n";
        return;
    }

    sort(sorted.begin(), sorted.end());
    int temp = INT_MAX;
    int temp2;


    for(int i = 0 ; i < n-1 ; i++){
        temp2 = abs(vec[i+1] - vec[i]);
        if(temp2 <= 1){
            cout<< 0;
            cout << "\n";
            return;
        } 
    }


    for(int i = 0 ; i < n -1  ; i++){
        if(abs(sorted[i+1].first - sorted[i].first)<=1 && (abs(sorted[i+1].second - sorted[i].second) < temp)){
            temp = abs(sorted[i+1].second - sorted[i].second);
        }
    }   

    if(temp == INT_MAX){
        cout << -1;
        cout << "\n";
        return;
    }

    cout << temp - 1;
    cout << "\n";
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
