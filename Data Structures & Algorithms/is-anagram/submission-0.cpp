class Solution {
public:
    bool isAnagram(string s, string t) {
    vector<int> ans(26);

     for(char c:s){
        ans[c-'a']++;
     }
     for(char c:t){
        ans[c-'a']--;
     }

     for(int it:ans){
        if(it!=0) return false;
     }

     return true;
    }
};
