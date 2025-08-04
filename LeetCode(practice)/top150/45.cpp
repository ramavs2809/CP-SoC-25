//https://leetcode.com/problems/jump-game-ii/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> v;
        int s=nums.size();
        for(int i=0;i<s;i++){v.push_back(nums[i]+i);}
        int x=s-1,y,cost=0;
        while(x>0){
            y=0;
            while(v[y]<x){y++;}
            x=y;
            cost++;
        }
        return cost;
    }
};