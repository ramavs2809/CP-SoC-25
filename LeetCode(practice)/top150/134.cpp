//https://leetcode.com/problems/gas-station/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(),s=0,is=0,mini=INT_MAX,x=0;
        vector<int> r;
        for(int i=0;i<n;i++){r.push_back(gas[i]-cost[i]);s+=r[i];}
        if(s<0){return -1;}
        for(int i=0;i<n;i++){
            is+=r[i];
            if(is<mini){x=i;mini=is;}
        }
        return (x+1)%n;
    }
};