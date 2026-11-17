class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int m=triplets.size();
        int n=triplets[0].size();
        vector<int> notAllowed(m,0);
         

        int ans[3]={0,0,0};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(triplets[j][i]>target[i]){
                    notAllowed[j]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(triplets[j][i]==target[i] && notAllowed[j]==0){
                    ans[i]=1;
                }
            }
        }

        for(int i=0;i<3;i++){
            if(ans[i]==0) return false;
        }
        return true;
    }
};