#include <bits/stdc++.h>
using namespace std;

class HappyStringCounter {
private:
    int a, b, c;
    int maxLen;
    unordered_set<string> longestStrings;
    
    void dfs(string s, int remA, int remB, int remC) {
        int n = s.size();
        bool canAdd = false;
        if (remA > 0) {
            if (n < 2 || !(s[n-1] == 'a' && s[n-2] == 'a')) {
                canAdd = true;
                dfs(s + 'a', remA - 1, remB, remC);
            }
        }
        if (remB > 0) {
            if (n < 2 || !(s[n-1] == 'b' && s[n-2] == 'b')) {
                canAdd = true;
                dfs(s + 'b', remA, remB - 1, remC);
            }
        }
        if (remC > 0) {
            if (n < 2 || !(s[n-1] == 'c' && s[n-2] == 'c')) {
                canAdd = true;
                dfs(s + 'c', remA, remB, remC);
            }
        }
        
        if (!canAdd) {
            int len = s.size();
            if (len > maxLen) {
                maxLen = len;
                longestStrings.clear();
                longestStrings.insert(s);
            } else if (len == maxLen) {
                longestStrings.insert(s);
            }
        }
    }
    
public:
    HappyStringCounter(int x, int y, int z) : a(x), b(y), c(z), maxLen(0) {}
    
    int countLongestHappyStrings() {
        if (a == 0 && b == 0 && c == 0) {
            return 0;
        }
        
        dfs("", a, b, c);
        return longestStrings.size();
    }
    
    void printLongestStrings() {
        cout << maxLen << endl;
        cout << longestStrings.size() << endl;
        cout << endl;
        for (const string& s : longestStrings) {
            cout << "  " << s << endl;
        }
    }
};

int main() {
    int a, b, c;
                                                                            
    cin >> a >> b >> c;
    
    HappyStringCounter counter(a, b, c);
    int result = counter.countLongestHappyStrings();
    
    cout  << result << endl;
    
    return 0;
}



