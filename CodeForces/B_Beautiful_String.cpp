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

bool palindrome(vector<int> &s){
    int l = 0;
    int r = s.size() - 1;
    while(l < r){
        if(s[l] == -1) l++;
        else if(s[r] == -1) r--;
        else {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
    }
    return true;
}

bool dfs(vector<int> &s, int flag, int i){
    if((i > s.size())) return false;
    if(i == s.size() && palindrome(s)){
        int counter = 0;
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(s[i] == -1) counter ++;
        }
        cout << counter;
        L;
        for(int i = 0;i<n;i++){
            if(s[i] == -1) cout << i+1 << " ";
        }
        L;
        return true;
    }
    else if(s.size() == i && !palindrome(s)) return false;

    int temp = s[i];
    if(s[i] == 0 && flag == 0){
        s[i] = -1;
        if(dfs(s,0,i+1)) return true;
        s[i] = temp;
    }

    else if(s[i] == 1){
        s[i] = -1;
        if(dfs(s,1,i+1)) return true;
        s[i] = temp;
    }

    if(dfs(s,flag,i+1)) return true;
    return false;
}
void solve() {
    // int n;
    // cin >> n;
    // vector<int> arr(n,0);
    // for(int i = 0; i < n; i++){
    //     cin >> arr[i];
    // }
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> arr(n,0);
    for(int i = 0; i < n; i++){
        arr[i] = int(s[i] - '0');
    }
    if(!dfs(arr,0,0)){
        cout << -1;
        L;
    }
    
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