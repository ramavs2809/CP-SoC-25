//https://leetcode.com/problems/minimum-removals-to-balance-array/
class Solution {
public:
    int minRemoval(vector<int>& nums,int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n==1){return 0;}
        else if(k==1){
            unordered_map<int,int> m;
            int rep=0;
            for(int i=0;i<n;i++){
                m[nums[i]]++;
                rep=max(rep,m[nums[i]]);
            }
            return n-rep;
        } 
        else{
            int i=0,j=n-1,c=0,x,y;
            while((long long)nums[j]>((long long)k * (long long)nums[i])){
                x=upper_bound(nums.begin(),nums.end(),((long long)k * (long long)nums[i]))-nums.begin();
                y=lower_bound(nums.begin(),nums.end(),nums[j],[&](int val,int target){
                    return (long long)k*(long long)val<=(long long)target;
                })-nums.begin();
                if((j+1-x)>=(y-i)){i++;}
                else{j--;}
                c++;
            }
            return c;
        }
    }
};