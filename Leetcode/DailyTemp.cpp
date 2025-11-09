class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stack;
        int size = temperatures.size();
        vector<int> answer{};
        for(int i = 0;i<size;i++){
            if(stack.empty()){
                stack.push(i);
                continue;
            } 
            while(temperatures[stack.top()] < temperatures[i]){
                answer.push_back(i-stack.top());
                stack.pop();
            }
            stack.push(i);
        }
        return answer;
    }
};