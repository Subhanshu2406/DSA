class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0;
        int leftMax = 0;
        for(auto c : s){
            if(c == '('){
                leftMin ++;
                leftMax ++;
            }
            else if(c == ')'){
                leftMin --;
                leftMax --;
            }
            else{
                leftMin --;
                leftMax ++;
            }

            if(leftMin < 0)leftMin = 0;
            if(leftMax < 0) return false;
        }
        return leftMin == 0;
    }
};

//this is the greedy solution
//think of this question as at any given point, how many left open parenthesis do we have?
//our goal is to close all left open parenthesis by the end of the array
//so we have 2 variables leftMax for max no of left open parenthesis till that index and similarly for leftMin for min no of left open parethesis
//when our wildcard appears, if we let it be ( we are increasing max no of left open possible and if we ) for the min no of left open till that index
//now if leftmin ever becomes negative we reset it to zero, basically this means at any index if we have 0 left parenthesis we do not want to have another ) as that would make it invalid ther on the spot
//finally we return if leftMin is 0 that means theres a possibility theres no open parenthesis so we reutn true
//if we get leftMax  < 0 at anypoint we reutnr false as that means even in best case scenario we would have no left open parenthesis and hence invalid
