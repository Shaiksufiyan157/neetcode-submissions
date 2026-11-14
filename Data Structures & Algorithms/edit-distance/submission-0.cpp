class Solution {
public:
vector<vector<int>> dp;
    int solve(int len1,int len2,string word1, string word2){
        if(len1==0) return len2;
        else if(len2==0) return len1;
        if(dp[len1][len2]!=-1) return dp[len1][len2];
        if(word1[len1-1]==word2[len2-1]){
            return dp[len1][len2]=solve(len1-1,len2-1,word1,word2);
        }
        else{
            return dp[len1][len2]=min({1+solve(len1,len2-1,word1,word2),1+solve(len1-1,len2,word1,word2),1+solve(len1-1,len2-1,word1,word2)});
        }
    }
    int minDistance(string word1, string word2) {
        int len1=word1.size();
        int len2=word2.size();
        dp.assign(len1+1,vector<int>(len2+1,-1));
        return solve(len1,len2,word1,word2);
    }
};