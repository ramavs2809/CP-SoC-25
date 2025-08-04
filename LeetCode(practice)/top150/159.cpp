//https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int x=nums.size();
        reverse(nums.begin(),nums.begin()+x-(k%x));
        reverse(nums.begin()+x-(k%x),nums.end());
        reverse(nums.begin(),nums.end());
    }
};