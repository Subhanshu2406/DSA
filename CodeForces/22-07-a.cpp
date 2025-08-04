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

void solve() {
    string s;
    cin >> s;
    unordered_map<char,int> map;
    for(char c : s) map[c] ++;
    string res = "";
    if(map['T'] > 0){
        int val = map['T'];
        map['T'] = 0;
        for(int i = 0 ;i < val;i++) res.push_back('T');
    }
    if(map['F'] > 0){
        int val = map['F'];
        map['F'] = 0;
        for(int i = 0 ;i < val;i++) res.push_back('F');
    }
    if(map['N'] > 0){
        int val = map['N'];
        map['N'] = 0;
        for(int i = 0 ;i < val;i++) res.push_back('N');
    }
    for(auto it = map.begin();it != map.end(); it ++){
        int val = it -> second;
        for(int i = 0 ;i < val;i++) res.push_back(it -> first);
    }

    cout << res;
    L;
    return;
}

    // int l = 0;
    // int r = 2;
    // while(r < s.size()){
    //     string temp = s.substr(l, r - l + 1);
    //     if(temp == "FFT"){
    //         char temp = s[l+1];
    //         s[l+1] = s[r];
    //         s[r] = temp;
    //         l = r;
    //         r = r + 2;
    //     }
    //     else {
    //         l++;
    //         r++;
    //     }
    // }

    // int n = s.size();
    // l = n - 2;
    // r = n;
    // while(l >= 0){
    //     string temp = s.substr(l, r - l + 1);
    //     if(temp == "NTT"){
    //         char temp = s[l+1];
    //         s[l+1] = s[l];
    //         s[l] = temp;
    //         r = l;
    //         l = l - 2;
    //     }
    //     else {
    //         l++;
    //         r++;
    //     }
    // }
    // cout << s;
    // L;
    // return;


int main() {
    fast_io
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}