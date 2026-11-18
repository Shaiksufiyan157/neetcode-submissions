class Solution {
public:
int currArea;
    void solve(int i,int j,vector<vector<int>>& visited,vector<vector<int>>& grid ,int m,int n){

        if(i>=m || j>=n || i<0 || j<0){
            return;
        }
        if(grid[i][j]==0 || visited[i][j]) return;

        visited[i][j]=1;
        currArea++;
        solve(i+1,j,visited,grid,m,n);
        solve(i,j+1,visited,grid,m,n);
        solve(i-1,j,visited,grid,m,n);
        solve(i,j-1,visited,grid,m,n);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> visited(m,vector<int>(n,0));

        int MaxArea=0;
        currArea=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    currArea=0;
                    solve(i,j,visited,grid,m,n);
                    MaxArea=max(MaxArea,currArea);
                }
            }
        }

        return MaxArea;
    }
};