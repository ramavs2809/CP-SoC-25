//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=1,n=s.size(),ml=0;
        map<char,int> m;
        for(int j=0;j<n;j++){
            if(m[s[j]]){i=max(i,m[s[j]]+1);}
            ml=max(ml,j-i+2);
            m[s[j]]=j+1;
            cout<<ml<<"-";
        }
        return ml;
    }
};