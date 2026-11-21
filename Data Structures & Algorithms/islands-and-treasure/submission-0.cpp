class Solution {
public:

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0},
                                    {0, -1}, {0, 1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto top=q.front();
            q.pop();
            int r=top.first;
            int c=top.second;

            for(int i=0;i<4;i++){
                int delr=r+dirs[i][0];
                int delc=c+dirs[i][1];

                if(delr>=m || delc>=n || delc<0 || delr<0 || 
                grid[delr][delc]!=INT_MAX) continue;

                grid[delr][delc]=grid[r][c]+1;
                q.push({delr,delc});
            }

        }
    }
};
