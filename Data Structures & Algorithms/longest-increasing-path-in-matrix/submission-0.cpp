class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0},
                                      {0, -1}, {0, 1}};
    vector<vector<int>> dp;
    int solve(int i,int j,vector<vector<int>>& matrix,int m,int n,int prevVal){
        if(i>=m || j>=n || i<0 || j<0) return 0;
        if(prevVal>=matrix[i][j]) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
    
        int res=1;
        for(auto d:directions){
            res=max(res,1+solve(d[0]+i,d[1]+j,matrix,m,n,matrix[i][j]));
        }
        return dp[i][j]=res;

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int maxi=0;
        dp.assign(m+1,vector<int>(n+1,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                maxi=max(maxi,solve(i,j,matrix,m,n,INT_MIN));
            }
        }
        return maxi;
    }
};