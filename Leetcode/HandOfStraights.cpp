class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> mp;

        for(int n : hand){
            mp[n]++;
        }

        for(int n : hand){
            auto it = mp.find(n);
            if(it -> second == 0) continue;
            int temp = it -> first;
            while(mp.count(temp-1)) temp--;
            int start = temp;

            while(mp.count(temp+1)) temp++;
            int end = temp;

            for(int i = start; i <= end; i++) {
                if(mp[i] <= 0) continue;
                int temp2 = mp[i];
                for(int j = i; j < groupSize + i; j++){
                    mp[j] -= temp2;
                    if(mp[j] < 0) return false;
                }   
            }
        }

        return true;
    }
};