class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            int left=i;
            int right=i;
            int count=0;

            while(left>=0 && right<n && s[left]==s[right]){
                left--;
                right++;
                count++;
            }
            left=i-1;
            right=i;
            
            while(left>=0 && right<n && s[left]==s[right]){
                left--;
                right++;
                count++;
            }
            ans+=count;

        }
        return ans;
    }
};