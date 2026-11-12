class Solution {
public:
    vector<vector<int>> dp;
    int solve(int n,vector<int>& coins,int amount){
        if(amount==0) return 1;
        if(n==0) return 0;
        if(dp[n][amount]!=-1) return dp[n][amount];

        if(amount>=coins[n-1]){
            return dp[n][amount]=solve(n,coins,amount-coins[n-1])+solve(n-1,coins,amount);
        }
        else return dp[n][amount]=solve(n-1,coins,amount);
        
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        dp.assign(n+1,vector<int>(amount+1,-1));
        return solve(n,coins,amount);
    }
};