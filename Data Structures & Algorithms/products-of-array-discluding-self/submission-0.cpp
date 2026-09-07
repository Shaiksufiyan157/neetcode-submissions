class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
int n=nums.size();

        vector<int> suffix(n);
        vector<int> prefix(n);
        vector<int> ans(n);
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i];
        }
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]*nums[i];
        }

        for(int i=0;i<n;i++){
            int leftIdx=i-1;
            int rightIdx=i+1;

            if(leftIdx<0){
                ans[i]=suffix[rightIdx];
            }
            else if(rightIdx>=n){
                ans[i]=prefix[leftIdx];
            }
            else ans[i]=prefix[leftIdx]*suffix[rightIdx];
        }

        return ans;
    }
};
