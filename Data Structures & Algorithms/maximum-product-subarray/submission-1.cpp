class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();

        int prefix=1,suffix=1;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            suffix=suffix*nums[n-i-1];
            prefix=prefix*nums[i];

            maxi=max({suffix,maxi,prefix});
            if(0==suffix) suffix=1;
            if(0==prefix) prefix=1;
        }

        return maxi;
    }
};
