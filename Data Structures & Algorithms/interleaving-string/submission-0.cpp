class Solution {
public:
    string ss1;
    string ss2;
    string ss3;
    vector<vector<int>> dp;
    bool solve(int l1,int l2,int l3){
        if(l3==0) return  l1==0 && l2==0;
        if(dp[l1][l2]!=-1) return dp[l1][l2];
        if((l1!=0 && ss1[l1-1]==ss3[l3-1]) && (l2!=0 && ss2[l2-1]==ss3[l3-1])){
            return dp[l1][l2]=solve(l1-1,l2,l3-1) || solve(l1,l2-1,l3-1);
        }
        else if(l1!=0 && ss1[l1-1]==ss3[l3-1]){
            return dp[l1][l2]=solve(l1-1,l2,l3-1);
        }
        else if(l2!=0 && ss2[l2-1]==ss3[l3-1]){
            return dp[l1][l2]=solve(l1,l2-1,l3-1);
        }
        return dp[l1][l2]=false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        ss1=s1;
        ss2=s2;
        ss3=s3;
        int l1=s1.length();
        int l2=s2.length();
        int l3=s3.length();
        dp.assign(l1+1,vector<int>(l2+1,-1));
        return solve(l1,l2,l3);
    }
};