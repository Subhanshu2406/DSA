class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        for(int asteroid : asteroids){
            if(stk.empty()) stk.push(asteroid);
            else if(stk.top() < 0 && asteroid > 0) stk.push(asteroid);
            else if(stk.top() > 0 && asteroid < 0){
                while(!stk.empty() && stk.top() > 0 && stk.top() <= abs(asteroid)){
                    if(stk.top() < abs(asteroid)) stk.pop();
                    else if(stk.top() == abs(asteroid)){
                        stk.pop();
                        asteroid = 0; //so taht this asteroid doesnt get pushed
                        break;
                    }
                } 
                if(stk.empty() && asteroid != 0) stk.push(asteroid);
                else if(!stk.empty() && stk.top() < 0 && asteroid < 0) stk.push(asteroid);
            }
            else stk.push(asteroid);
        }
        vector<int> res;
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }

        reverse(res.begin(),res.end());
        return res;
    }
};