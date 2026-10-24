class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n=queries.size();
        int m=intervals.size();
        vector<int> result(n,-1);
        vector<vector<int>> events;

        for(int i=0;i<m;i++){
            events.push_back({intervals[i][0],1,intervals[i][1]-intervals[i][0]+1,i});
            events.push_back({intervals[i][1],3,intervals[i][1]-intervals[i][0]+1,i});
        }
        for(int i=0;i<n;i++){
            events.push_back({queries[i],2,i});
        }
        sort(events.begin(), events.end(),[](const vector<int> &a,const vector<int> &b){
            return a[0]==b[0] ? a[1]<b[1] :a[0]<b[0];
        });
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> inactive(m,false);
        for(int i=0;i<events.size();i++){
            if(1==events[i][1]){
                pq.push({events[i][2],events[i][3]});
            }
            else if(3==events[i][1]){
                inactive[events[i][3]]=true;
            }
            else {
                while(!pq.empty() && inactive[pq.top().second]){
                    pq.pop();
                }
                if(!pq.empty()){
                int queryIdx=events[i][2];
                result[queryIdx]=pq.top().first;
                }
            }
        }
        return result;
    }
};