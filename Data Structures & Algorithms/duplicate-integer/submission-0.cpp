class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int it:nums){
            st.insert(it);
        }

        int stSize=st.size();
        int nSize=nums.size();

        return !(nSize==stSize);
    }
};