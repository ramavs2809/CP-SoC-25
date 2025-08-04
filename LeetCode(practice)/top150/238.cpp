//https://leetcode.com/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> x;
        int n=nums.size(),left[n],right[n];
        left[0]=1;
        right[n-1]=1;
        for(int i=1;i<n;i++){left[i]=left[i-1]*nums[i-1];}
        for(int i=n-2;i>=0;i--){right[i]=right[i+1]*nums[i+1];}
        for(int i=0;i<n;i++){x.push_back(left[i]*right[i]);}
        return x;
    }
};