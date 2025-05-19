//O(nk) brute force solution using maps
class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int,int> map = {};
            for(int num : nums){
                map[num]++;
            }
    
            vector<int> answer ={};
            for(int i=0;i<k;i++){
                int number = map.begin()->second;
                int index = map.begin()->first;
                for(auto element : map){
                    if(element.second > number) 
                    {
                        number = element.second;
                        index = element.first;
                    }
                }
                map.erase(index);
                answer.push_back(index);
            }
    
            return answer;
        }
    };