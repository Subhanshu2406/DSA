class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        vector<vector<int>> res;
        int n = arr.size();
        if(arr.size() < 4) return res; 
        sort(arr.begin(), arr.end());

        int prevA = INT_MAX;
        for(int a = 0; a < n-3; a++){
            if(arr[a] == prevA) continue;
            prevA = arr[a];
            
            int prevB = INT_MAX;
            for(int b = a + 1; b < n - 2; b++){
                if(arr[b] == prevB) continue;
                prevB = arr[b];

                int l = b + 1;
                int r = n - 1;

                int flag = 0;
                while(l < r && flag == 0){
                    if((long long)arr[a] + arr[b] + arr[l] + arr[r] > target) r--;
                    else if((long long)arr[a] + arr[b] + arr[l] + arr[r] < target) l++;
                    else if((long long)arr[a] + arr[b] + arr[l] + arr[r] == target){
                        res.push_back({arr[a],arr[b],arr[l],arr[r]});
                        if(arr[l] == arr[r]) flag = 1;
                        int temp = arr[l];
                        while(l < n && arr[l] == temp) l++;
                    }
                }
            }
        }

        return res;
    }
};


//if all values should be distinct
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        vector<vector<int>> res;
        int n = arr.size();
        if(arr.size() < 4) return res; 
        sort(arr.begin(), arr.end());

        int prevA = INT_MAX;
        for(int a = 0; a < n-3; a++){
            if(arr[a] == prevA) continue;
            prevA = arr[a];
            
            int prevB = INT_MAX;
            for(int b = a + 1; b < n - 2; b++){
                if(arr[b] == prevB) continue;
                prevB = arr[b];

                unordered_set<int> s;
                int tempT = target - arr[a] - arr[b];

                int start = b + 1;
                while(arr[b] == arr[start] && start < n) start++;

                for(int c = start; c < n; c++){
                    if(s.find(tempT - arr[c]) != s.end() && (tempT - arr[c] != arr[c])) res.push_back({arr[a], arr[b], arr[c], tempT - arr[c]});
                    s.insert(arr[c]);
                }
            }
        }

        return res;
    }
};