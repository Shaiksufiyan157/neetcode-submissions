class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       int row[9]={0};
        int col[9]={0};
        int squares[9]={0};

        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if('.'==board[r][c]) continue;

                int number=board[r][c]-'1';
                int SqKey=(r/3)*3 + c/3;
                if((row[r] & (1<<number)) || (col[c] & (1<<number)) || (squares[SqKey] & (1<<number))) return false;
                row[r]|=(1<<number);
                col[c]|=(1<<number);
                squares[SqKey]|=(1<<number);
            }
        }
        return true; 
    }
};
