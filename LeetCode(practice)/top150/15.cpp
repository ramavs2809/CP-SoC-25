//https://leetcode.com/problems/3sum/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> v;
        map<int,int> ma;
        map<vector<int>,int> c;
        for(int i=0;i<n;i++){
            ma[nums[i]]++;
        }
        int sum;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n-1;j++){
                sum=-(nums[i]+nums[j]);
                if((sum>=nums[j+1])&&(ma[sum])&&(!c[{nums[i],nums[j],sum}])){v.push_back({nums[i],nums[j],sum});c[{nums[i],nums[j],sum}]++;}
            }
        }
        return v;
    }
};