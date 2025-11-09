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
    int n;
    cin >> n;
    vector<int> A(n,0);
    vector<int> B(n,0);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    for(int i = 0; i < n; i++){
        cin >> B[i];
    }

    int mem = 2 * pow(10,5);
    vector<int> visit(mem+1,0);

    for(int i = 0;i < n;i++){
        int curr = A[i];
        if(visit[curr] == 1){
            cout << 0;
            L;
            return;
        }

        

        int temp = A[i];
        while(temp <= mem){ 
            visit[temp] = 1;
            temp = temp + curr;
        }
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


vector<bool> primeNumbers(int n){
    vector<bool> arr(n+1, true);
    arr[0] = false;
    arr[1] = false;

    for(int i = 2; i <= n; i++){
        if(arr[i] == false) continue;

        int temp = 2 * arr[i];
        while(temp <= n){
            arr[temp] = false;
            temp = temp + arr[i];
        }
    }
}