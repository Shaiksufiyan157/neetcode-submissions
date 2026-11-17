class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0) return false;

        unordered_map<int,int> mp;

        for(int it:hand){
            mp[it]++;
        }
        sort(hand.begin(), hand.end());
        for(int it:hand){
            if(mp[it]>0){
                for(int i=it;i<it+groupSize;i++){
                    if(mp[i]<=0) return false;
                    mp[i]--;
                }
            }
        }

        return true;
    }
};