class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int start=0;
        int subLen=0;

        for(int i=0;i<n;i++){
            int left=i-1;
            int right=i+1;

            while(left>=0 && right<n && s[left]==s[right]){
                left--;
                right++;
            }
            if(right-left-1>subLen){
                start=left+1;
                subLen=right-left-1;
            }
            left=i-1;
            right=i;
            while(left>=0 && right<n && s[left]==s[right]){
                left--;
                right++;
            }
            if(right-left-1>subLen){
                start=left+1;
                subLen=right-left-1;
            }
        }

        return s.substr(start,subLen);
    }
};