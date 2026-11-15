class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int JumpIndex=0;
        int jumps=0;
        int maxJump=0;

        for(int i=0;i<n;i++){
            maxJump=max(maxJump,i+nums[i]);

            if(JumpIndex==i){
                jumps++;
                JumpIndex=maxJump;

                if(JumpIndex>=n-1) return jumps;
            }
        }
        return 0;
    }
};
