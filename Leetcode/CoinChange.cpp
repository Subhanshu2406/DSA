//We first have the target sum
//We run dfs, top-down dp using memoization
//First we take the target sum and see possibilities for the all coins then run the same process in the lower dfs level 
//So we run dfs till it either reaches the remaining sum == 0, we return the 1(since we found a solution) and now the upper level will take the min coins from all possible dfs and return min + 1 to its upper level
//and if remaining sum is less than value of lowest coin then we return 0 up since we did not find a viable solution
//after returning and going up, we store the coins taken in a hashmap like remainingTarget : coins such that in future if we come across the same remaining target we wont need to rn the dfs again
//Mistake i made: one thing you might think of is to sort coins decreasing and then also have an index where u run the for loop from i = index meaning u wont have to repeat certain simulations(basically say we have denominations 3 5 7 so we first check all possibilities using just 7 like say 7 7 7 only then we go for 7 7 5 and so on, this way later when we come back to top most layer and go for 5 we wont have to deal with cases like 5 7 3 since 7 5 3 was already convered), this however doesnt work as in that case in memoization we would have to store both index and remainingAmount and then the value would be remainingCoins which we arent doing so it fails
//Time complexity is O(N * Amount) ,although using for loop it is exponential but as we use memoization we use a hashmap for all possible values from [0,Amount] so atmax we are computing for amount no of steps and for each amount we calculate operations for N coins so O(amount*N)
//basically remainingAmount will run till its entire for loop is done so think this keeps going deeper in dfs till for a specific remainingAmount(when remainingAmount < leastvalueCoin) its for loop runs for n steps and all return INT_MAX so only now can we go back the dfs. Hence all remainingAmount run N steps to calculate thier coins required.
class Solution {
    unordered_map<int,int> memo;
public:
    int coinChange(vector<int>& coins, int amount) {
        int res = dfs(coins,amount,0);      //INDEX IS NOT REQUIRED IN THIS QUESTION, I WAS THINKING OF A SOLUTION USING IT BUT I COULDNT SO IGNORE IT
        if(res == INT_MAX) return -1;
        return res;
    }

    int dfs(vector<int>& coins, int remainingAmount, int index){
        if(remainingAmount == 0) return 0;
        else if(remainingAmount < coins[0]) return INT_MAX;

        if(memo.find(remainingAmount) != memo.end()) return memo[remainingAmount];

        int minCoins = INT_MAX;
        for(int i = 0; i < coins.size() ;i++){
            minCoins = min(minCoins,dfs(coins,remainingAmount - coins[i],i));
        }

        if(minCoins == INT_MAX){
        memo[remainingAmount] = INT_MAX;
        return INT_MAX;
        }
        else memo[remainingAmount] = minCoins + 1;

        return minCoins + 1; 
    }
};

//greedy doesnt work in this question as its not necessary to keep adding the highest coins only