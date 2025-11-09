class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordermap<char,int> map1;
        unordermap<char,int> map2;

        for(char c: s1){
            map1[c]++;
        }

        for(char c: s2){
            map2[c]++;
        }

        for(auto it = map1.begin() ; it != map1.end() ; it++){
            if(it -> second > map2[it->first]) return false;
        }
        return true;
    }
};