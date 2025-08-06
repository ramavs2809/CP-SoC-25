//https://leetcode.com/problems/container-with-most-water/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int mp=0,mi,ma;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({height[i],i});
        }
        sort(v.begin(),v.end());
        mi=v[n-1].second;
        ma=v[n-1].second;
        for(int i=n-2;i>=0;i--){
            mp=max(mp,max((v[i].first*abs(v[i].second-mi)),(v[i].first*abs(ma-v[i].second))));
            mi=min(mi,v[i].second);
            ma=max(ma,v[i].second);
        }
        return mp;
    }
};