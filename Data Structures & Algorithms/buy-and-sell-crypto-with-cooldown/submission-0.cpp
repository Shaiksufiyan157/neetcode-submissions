class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(vector<int>& prices,int n,int index,int buy,int cooldown){
        if(index==n) return 0;
        if(dp[index][buy][cooldown]!=-1) return dp[index][buy][cooldown];
        if(cooldown){
            return dp[index][buy][cooldown]=solve(prices,n,index+1,buy,0);
        }
        else if(buy){
            return dp[index][buy][cooldown]=max(solve(prices,n,index+1,buy,cooldown),-prices[index]+solve(prices,n,index+1,0,cooldown));
        }
        else 
        return dp[index][buy][cooldown]=max(solve(prices,n,index+1,0,cooldown),prices[index]+solve(prices,n,index+1,1,1));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        dp.assign(n+1,vector<vector<int>>(2,vector<int>(2,-1)));

        int profit=solve(prices,n,0,1,0);
        return profit;
    }
};