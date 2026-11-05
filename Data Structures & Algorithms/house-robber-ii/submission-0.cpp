class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(1==n) return nums[n-1];

        vector<int> dp(n+2,0);

        for(int i=n-1;i>=1;i--){
            dp[i]=max(nums[i]+dp[i+2],dp[i+1]);
        }
        int option1=dp[1];
        dp.assign(n+2,0);

        for(int i=n-2;i>=0;i--){
            dp[i]=max(nums[i]+dp[i+2],dp[i+1]);
        }
        int option2=max(dp[0],dp[1]);
        return max(option1,option2);

    }
};
