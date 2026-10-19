class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        vector<int> newInterval=intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(newInterval[1]>= intervals[i][0]){
                newInterval[1]=max(newInterval[1],intervals[i][1]);
                ans.pop_back();
                ans.push_back(newInterval);
            }
            else{
                newInterval=intervals[i];
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};