class Solution {
public:
    vector<int> partitionLabels(string s) {
     vector<int> mp(26,-1);
     int n=s.length();
     for(int i=0;i<n;i++){
        if(mp[s[i]-'a']==-1){
            mp[s[i]-'a']=i;
        }
     }
     int cursize=n;
     int farmost=cursize;
     vector<int> ans;
     for(int i=n-1;i>=0;i--){
        farmost=min(mp[s[i]-'a'],farmost);

        if(farmost==i){
            ans.push_back(cursize-i);
            cursize=i;
        }
     }
     reverse(ans.begin(),ans.end());

     return ans;
    }
};