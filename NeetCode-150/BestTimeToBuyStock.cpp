//solution using dynamic programming O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0; 
        
        for (int price : prices) {
            minPrice = std::min(minPrice, price);
            maxProfit = std::max(maxProfit, price - minPrice);
        }
        
        return maxProfit;
    }
};

//this was a solution using the two pointer/sliding window method and it is O(n) time complexity
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int l = 0;
        int r = 1;

        int minProfit = 0;
        int min = prices[0];

        while(l < r && r < size){
            int profit = prices[r] - prices[l];
            if(profit > minProfit) minProfit = profit;
            if(prices[r] < min){
                min = prices[r];
                l = r;
            }
            r++;
        }

        return minProfit;
    }
};
