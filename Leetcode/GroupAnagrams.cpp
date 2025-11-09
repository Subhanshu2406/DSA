class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            int numberofStrings = strs.size();
            unordered_map<char,int> map[numberofStrings] {};
            for(int i = 0;i < numberofStrings;i++){
                int numberofCharacters = strs[i].size();
                for(int j = 0 ;j<numberofCharacters;j++){
                    map[i][strs[i][j]] ++;
                } 
            } 

            int noofAnagrams = 0;
            vector<vector<string>> answer = {};

            for(int i=0;i<noofStrings;i++){
                for(int j=0;j<noofAnagrams;j++){
                    
                }
            }


        }
    };