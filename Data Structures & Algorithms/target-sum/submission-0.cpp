class Solution {
public:
    vector<vector<int>> dp;
    int solve(int n,vector<int>& nums,int amount){
        if(n==0){
            return amount==0?1:0;
        }

        if(dp[n][amount]!=-1) return dp[n][amount];

        if(amount>=nums[n-1]){
            return dp[n][amount]=solve(n-1,nums,amount-nums[n-1])+solve(n-1,nums,amount);
        }
        else return dp[n][amount]=solve(n-1,nums,amount);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);

        if((sum+target)%2==1 || sum<abs(target)) return 0;

        dp.assign(n+1,vector<int>(((sum+target)/2)+1,-1));

        return solve(n,nums,(sum+target)/2);
    }
};