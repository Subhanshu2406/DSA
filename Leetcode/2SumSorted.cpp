class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            int* arr = &numbers[0];
            int size = numbers.size();
            int l = 0;
            int r = size - 1;
    
            vector<int> answer {};
            while(l <= r){
                if(target == arr[l] + arr[r]){
                answer.push_back(l+1);
                answer.push_back(r+1);
                return answer;
                }
    
                else if(target > arr[l] + arr[r]) l++;
                else r--;
    
            }
            return numbers;
    
        }
    };