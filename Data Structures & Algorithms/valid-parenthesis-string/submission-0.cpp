class Solution {
public:
    bool checkValidString(string s) {
        int n=s.length();

        int maxColOpen=0;
        int minColOpen=0;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                maxColOpen++;
                minColOpen++;
            }
            else if(s[i]==')'){
                maxColOpen--;
                minColOpen--;
            }
            else {
                maxColOpen++;
                minColOpen--;
            }
            if(minColOpen<0) minColOpen=0;

            if(maxColOpen<0) return false;
        }

        return minColOpen==0;
    }
};