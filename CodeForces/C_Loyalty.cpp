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
    long long n;
    long long k;
    cin >> n >> k;
    vector<long long> arr(n,0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());

    long long l = 0;
    long long r = n - 1;
    long long res = 0;
    vector<long long> order;
    long long total = 0;

    while(l <= r){
        int tempK = k;
        k = k - (total % k);

        if(arr[r] >= k){
            res += arr[r];
            total += arr[r];
            order.push_back(arr[r]);
            r--;
        }

        else{
            int left = k - arr[r];
            total += arr[r];
            while(l < r && left > 0){
                left -= arr[l];
                total += arr[l];
                order.push_back(arr[l]);
                l++;
            }
            order.push_back(arr[r]);

            if(left > 0) break;
            else if(left <= 0){
                res += arr[r];
                r--;
            }
        }
        k = tempK;
    }

    cout << res;
    L;
    long long siz = order.size();
    for(int i = 0;i < siz;i++){
        cout << order[i] << " ";
    }
    L;
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