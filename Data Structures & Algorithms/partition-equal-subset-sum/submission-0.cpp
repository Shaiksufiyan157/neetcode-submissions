class Solution {
public:
    vector<vector<int>> dp;
    bool solve(vector<int> nums,int n,int target){
        if(target==0) return true;
        if(n==0) return false;

        if(dp[n][target]!=-1) return dp[n][target];

        if(target>=nums[n-1]) 
        return dp[n][target]=solve(nums,n-1,target-nums[n-1]) || solve(nums,n-1,target);

        else return dp[n][target]=solve(nums,n-1,target);
    }
    bool canPartition(vector<int>& nums) {
      int n=nums.size();
      int sum=accumulate(nums.begin(),nums.end(),0);

      if(sum%2==1) return false;
      dp.assign(n+1,vector<int>((sum/2)+1,-1));

      return solve(nums,n,sum/2);  
    }
};