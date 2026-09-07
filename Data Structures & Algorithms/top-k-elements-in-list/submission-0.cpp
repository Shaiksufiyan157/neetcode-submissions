class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
              vector<int> ans;
        unordered_map<int,int> mp;

        for(int num:nums){
            mp[num]++;
        }
        auto comp=[&mp](int n1,int n2){ return mp[n1]>mp[n2];};
        priority_queue<int,vector<int>,decltype(comp)> Mheap(comp);
        for(auto &pair:mp){
            Mheap.push(pair.first);
            if(Mheap.size()>k) Mheap.pop();
        }
        while(k--){
            ans.push_back(Mheap.top());
            Mheap.pop();
        }
        return ans; 
    }
};
