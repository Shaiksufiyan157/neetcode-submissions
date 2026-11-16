class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas=accumulate(gas.begin(),gas.end(),0);
        int totalCost=accumulate(cost.begin(),cost.end(),0);

        if(totalCost>totalGas) return -1;
        int total=0;
        int idx=0;
        for(int i=0;i<cost.size();i++){
            total+=(gas[i]-cost[i]);

            if(total<0){
                total=0;
                idx=i+1;
            }
        }
        return idx;
    }
};
