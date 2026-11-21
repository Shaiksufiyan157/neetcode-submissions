class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0},
                                    {0, -1}, {0, 1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        int maxMinutes=0;
        while(!q.empty()){
            auto [top,minutes]=q.front();
            q.pop();
            int r=top.first;
            int c=top.second;
            // int minutes=minutes

            for(int i=0;i<4;i++){
                int delr=r+dirs[i][0];
                int delc=c+dirs[i][1];
                maxMinutes=max(maxMinutes,minutes);
                if(delc>=n || delr>=m || delc<0 || delr<0 || grid[delr][delc]!=1){
                    continue;
                }
                grid[delr][delc]=2;

                q.push({{delr,delc},minutes+1});
                

            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }

        }

        return maxMinutes;
    }
};