//https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> v;
        int s=nums.size();
        for(int i=0;i<s;i++){v.push_back(nums[i]+i);}
        int x=s-1,y;
        while(x>0){
            y=0;
            while(v[y]<x){y++;}
            if(y==x){return false;}
            x=y;
        }
        return true;
    }
};