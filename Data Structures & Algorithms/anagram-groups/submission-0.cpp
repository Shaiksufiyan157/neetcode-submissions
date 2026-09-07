class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
             unordered_map<string,vector<string>> mp;
        for(string s:strs){
            vector<int> freq(26);
            for(char c:s){
                freq[c-'a']++;
            }
            string hash="";
            for(int it:freq){
                hash+=(it);
                hash+='#';
            }
            mp[hash].push_back(s);
        }
        vector<vector<string>> result;

        for(auto it:mp){
            result.push_back(it.second);
        }

        return result;   
    }
};
