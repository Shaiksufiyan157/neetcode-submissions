class Solution {
public:
    int m,n;

    void dfs(int r,int c,vector<vector<char>>& board, vector<vector<int>>& visited){
        if(r<0 || c<0 || c>=n || r>=m) return;
        if(visited[r][c] || board[r][c]=='X') return;
        visited[r][c]=1;
        dfs(r-1,c,board,visited);
        dfs(r+1,c,board,visited);
        dfs(r,c-1,board,visited);
        dfs(r,c+1,board,visited);
    }
    void solve(vector<vector<char>>& board) {
        m=board.size();
        n=board[0].size();

        vector<vector<int>> visited(m,vector<int>(n,0));

        for(int i=0;i<n;i++){
            if(board[0][i]=='O') dfs(0,i,board,visited);
        }

        for(int i=0;i<m;i++){
            if(board[i][0]=='O') dfs(i,0,board,visited);
        }
        for(int i=0;i<m;i++){
            if(board[i][n-1]=='O') dfs(i,n-1,board,visited);
        }

        for(int i=0;i<n;i++){
            if(board[m-1][i]=='O') dfs(m-1,i,board,visited);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]) board[i][j]='X';
            }
        }
    }
};