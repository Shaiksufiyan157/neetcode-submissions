class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        int rem;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            rem=target-num;
            if(mpp.find(rem)!=mpp.end()){
                return {mpp[rem],i};
            }
           mpp[num]=i; 

        }
return {-1,-1};
    }
};
