class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();

        int sum=1;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            sum*=nums[i];
            maxi=max(sum,maxi);
            if(0==sum) sum=1;
        }
        sum=1;
        for(int i=n-1;i>=0;i--){
            sum*=nums[i];
            maxi=max(sum,maxi);
            if(0==sum) sum=1;
        }
        return maxi;
    }
};
