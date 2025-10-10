#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> arrA(n), arrB(n);
    arrA[0] = (s[0] == 'a');
    arrB[0] = (s[0] == 'b');
    for(int i = 1; i < n; i++) {
        arrA[i] = arrA[i-1] + (s[i] == 'a');
        arrB[i] = arrB[i-1] + (s[i] == 'b');
    }
    int total_a = arrA[n-1], total_b = arrB[n-1];
    if(total_a == total_b) {
        cout << 0 << "\n";
        return;
    }
    if(total_a == 0 || total_b == 0) {
        cout << -1 << "\n";
        return;
    }
    int diff = abs(total_a - total_b);
    int res = n;
    if(total_a > total_b) {
        int l = 0, r = 0;
            while(l < n && n > r) {
                int count = arrA[r] - arrB[l];
                if(count > diff) l++;
                else if(count < diff) r++;
                else {
                    res = min(res, r - l + 1);
                    r++;
                    l++;
                }
            }
    } else {
        int l = 0, r = 0;
            int count = arrB[r] - arrA[l];
            while(l < n && r < n) {
                int count = arrB[r] - arrA[l];
                if(count > diff) l++;
                else if(count < diff) r++;
                else if(count == diff){
                    res = min(res,r - l + 1);
                    l++;
                    r++;
                }
            }
    }
    cout << (res == n ? -1 : res) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
