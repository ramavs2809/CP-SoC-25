//https://leetcode.com/problems/minimum-size-subarray-sum/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int r=0,n=nums.size();
        int sum=0;
        int l=1,h=n,m;
        for(int i=0;i<n;i++){sum+=nums[i];}
        if(sum<target){return 0;}
        while(l<h){
            sum=0;
            bool found=false;
            m=(l+h)/2;
            for(int j=0;j<m;j++){
                sum+=nums[j];
            }
            if(sum>=target){found=true;}
            for(int j=m;j<n;j++){
                sum+=(nums[j]-nums[j-m]);
                if(sum>=target){found=true;break;}
            }
            cout<<found<<"--";
            if(found){h=m;}
            else{l=m+1;}
            cout<<h<<"-";
        }
        return h;
    }
};