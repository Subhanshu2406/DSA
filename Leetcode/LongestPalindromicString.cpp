//Approach: this is a top-down dp solution using memoization. Basically we set two pointers at start and end of the string.
//Next we check if its a palindrome if it is, we store this substring in the memo vector and if its not we run two calls, one where we did r-- and one where we did l--
//this way we technically explore all possible substrings and it is more time efficient than brute force checking all substrings since for a particular substring if it was processed earlier we store the best possible substring within it.
//the core idea is once we found a palindromic substring we would return location of that substring , now the bigger substring will compare the two calls it made and store the better(larger) substring within it which was a palindrome although this bigger substring might not be a palindrome
//this way even if a substring is not a palindrome but was processed earlier we would store its outcome to save time
//n^2 possible substrings and each substring also has a palindrome checker so n operations there so overall O(n^3).
//however instead of checking the entire substring again and again, we use memoization in a way like: for a substring l,r if char[l] == char[r] and palindrome(l+1,r-1) is true then this will be reduced to O(n^2) time complexity
class Solution {
    vector<vector<pair<int,int>>> memo;
public:
    string longestPalindrome(string s) {
        int size = s.size();
        vector<pair<int,int>> temp(size,{0,-1});
        memo.resize(size,temp);
        pair<int,int> res = dfs(s,0,size - 1);
        string ans = s.substr(res.first, res.second - res.first + 1);
        return ans;
    }

    pair<int,int> dfs(string& s,int l,int r){

        if(memo[l][r].second != -1) return memo[l][r];
        if(palindrome(s,l,r) || l == r){
            memo[l][r] = {l,r};
            return {l,r};
        }
        if(l > r) return {-1,-1};

        pair<int,int> temp1 = dfs(s,l + 1,r);
        pair<int,int> temp2 = dfs(s,l,r - 1);
        int size1 = temp1.second - temp1.first + 1;
        int size2 = temp2.second - temp2.first + 1;
        if(size1 > size2) memo[l][r] = {temp1.first,temp1.second};
        if(size1 <= size2) memo[l][r] = {temp2.first,temp2.second};
        return memo[l][r]; 
    }

    bool palindrome(string& s,int l,int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};

//we can get a O(n^2) solution using two pointers or a better approached dp, basically we traverse through the array
//in two pointer approach, remember when taking a char as center of palindrome, thsi is only one case for odd length, for even length palindrome the ith and i+1th char together make the center and both are same char
//now for each element in array we assume it to be centre of palindrome or it and the next element together to be center of palindrom and we set l and r at i and keep doing l-- and r++ till the chars are not same and update the max variable
//we can use a specific algorithm aswell for O(N) solution.