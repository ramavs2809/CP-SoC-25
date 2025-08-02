//https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> v;
        int prev=-1;
        bool found=false;
        for(int i=0;i<nums.size();i++){
            v.push_back(nums[i]);
            if(((i+1)<nums.size())&&(nums[i+1]==nums[i])){v.push_back(nums[i+1]);}
            int j=i;
            while((j<nums.size())&&(nums[j]==nums[i])){j++;}
            i=j-1;
        }
        for(int i=0;i<v.size();i++){
            nums[i]=v[i];
        }
        return v.size();
    }
};