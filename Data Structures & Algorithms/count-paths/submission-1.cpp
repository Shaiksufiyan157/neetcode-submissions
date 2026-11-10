class Solution {
public:
    vector<vector<int>> dp;
    int solve(int start,int end,int m,int n){
        if(start>=m || end>=n) return 0;

        if(start==m-1 && end==n-1) return 1;

        if(dp[start][end]!=-1) return dp[start][end];
        
        return dp[start][end]=solve(start+1,end,m,n)+solve(start,end+1,m,n);
    }
    int uniquePaths(int m, int n) {
        dp.assign(m+1,vector<int>(n+1,-1));
        return solve(0,0,m,n);
    }
};