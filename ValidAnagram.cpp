class Solution {
    public:
        bool isAnagram(string s, string t) {
            unordered_map<char,int> s1 = {};
            unordered_map<char,int> s2 = {};

            int size1 = s.size();
            int size2 = t.size();

            for(int i = 0; i<size1;i++){
                auto it = s1.find(s[i]);
                if(it == s1.end()) s1.insert({s[i],1});
                else it->second++;
            }

            for(int i = 0; i<size2;i++){
                auto it = s2.find(s[i]);
                if(it == s2.end()) s2.insert({s[i],1});
                else it->second++;
            }
            
            int count1 = s1.size();
            int count2 = s2.size();
            if(count1 != count2) return false;

            for(auto c : s1){
                auto it = s2.find(c.first);
                if(it == s2.end()) return false;
                else if(s1[c.first] != s2[it->first]) return false;
            }

            return true;
        }

    };
