class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        vector<int> dp(n+1);
        dp[n]=1;

        for(int i=n-1;i>=0;i--){
            if(s[i]=='0') dp[i]=0;

            else {
                int op=0;
                op+=dp[i+1];

                if(i+1<n && stoi(s.substr(i,2))<=26){
                    op+=dp[i+2];
                }
                dp[i]=op;
            }
        }

        return dp[0];
    }
};
