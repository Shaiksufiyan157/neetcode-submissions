class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int end=intervals[0][1];
        int to_remove=0;
        for(int i=1;i<intervals.size();i++){
            if(end>intervals[i][0]){
                end=min(end,intervals[i][1]);
                to_remove++;
            }
            else end=intervals[i][1];
        }

        return to_remove;

    }
};