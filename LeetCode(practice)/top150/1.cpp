//https://leetcode.com/problems/two-sum/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){v.push_back({nums[i],i});}
        int i=0,j=n-1,sum;
        sort(v.begin(),v.end());
        while(true){
            sum=v[i].first+v[j].first;
            if(sum>target){j--;}
            else if(sum<target){i++;}
            else{return {v[i].second,v[j].second};}
        }
    }
};