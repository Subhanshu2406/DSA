class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            unordered_map<int,int> map = {};

            for(int num : nums){
                map[num]++;
            }

            int max = 1;

            for(int num : nums){
                if(!map.count(num)) continue;
                int counter = below(num - 1,map) + above(num + 1,map);
                map.erase(num);
                if(counter > max) max = counter;
            }
            return max;
        }

        int below(int num,unordered_map<int,int>& map){
            int counter1 = 0;
            while(map.count(num)){
                map.erase(num);
                counter1++;
                num--;
            }
            return counter1;
        }

        int above(int num,unordered_map<int,int>& map){
            int counter2 = 0;
            while(map.count(num)){
                map.erase(num);
                counter2++;
                num++;
            }
            return counter2;
        }

    };