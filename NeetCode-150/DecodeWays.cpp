//We use bottom up dp here, the recurrence relation being dp[i] = d[i-1] + dp[i-2] but with constraints
//Pick the s[i] , now when decoding ways we have this number in 2 ways, either on its own or with another number(since it can be 10-26 aswell)
//so first if s[i] is not zero then we can have it on its own meaning the no of ways to decode would be just dp[i-1] , basically meaning upon having s[i] as a valid individual decode, no of decodings till the ith string is same as i-1th string
//now if s[i] and s[i-1] make a valid two digit code we can have that no as a valid decode and attach to all possible decodings for the string formed till i-2th chars, so in this case we add dp[i-2] aswell. 
//dp[0] is 1 or 0(if s[0] is 0) 
//dp[1] is 0 if the two digit code it makes with s[0] is between 00-09(leading no is 0), if its 10 or 20 , it is 1 and if more than 26 than also 1 and if 10-26(exceptioon of 10 and 20) it is 2
class Solution {
public:
    int numDecodings(string s) {
        int n  = s.size();
        vector<int> dp(n,0);

        if(s[0] - '0' != 0) dp[0] = 1;
        else{
            return 0;
        }

        if(n == 1) return dp[0];

        int firstChar = s[0] - '0';
        int secondChar = s[1] - '0';

        if(firstChar == 0 || (firstChar > 2 && secondChar == 0)) dp[1] = 0;
        else if((firstChar == 1 && secondChar != 0) || firstChar == 2 && (secondChar != 0 && secondChar <= 6)) dp[1] = 2;
        else dp[1] = 1;

        for(int i = 2;i < n; i++){
            if(s[i] - '0' != 0) dp[i] += dp[i-1];
            if(s[i-1] - '0' == 1 || (s[i-1] - '0' == 2 && s[i] - '0' <= 6)) dp[i] += dp[i-2];
        }

        return dp[n-1];

    }
};