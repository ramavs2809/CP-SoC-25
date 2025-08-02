//https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/description/
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size(),m=waterStartTime.size();
        int n1=INT_MAX,m1=INT_MAX,n2=INT_MAX,m2=INT_MAX;
        for(int i=0;i<n;i++){
            n1=min(n1,landStartTime[i]+landDuration[i]);
        }
        for(int i=0;i<m;i++){
            m1=min(m1,waterStartTime[i]+waterDuration[i]);
        }
        for(int i=0;i<n;i++){
            if(landStartTime[i]<=m1){n2=min(n2,m1+landDuration[i]);}
            else{n2=min(n2,landStartTime[i]+landDuration[i]);}
        }
        for(int i=0;i<m;i++){
            if(waterStartTime[i]<=n1){m2=min(m2,n1+waterDuration[i]);}
            else{m2=min(m2,waterStartTime[i]+waterDuration[i]);}
        }
        return min(n2,m2);
    }
};