//https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    string reverseWords(string s) {
        int n=s.size(),j=n-1,i=n;
        string x="";
        while(true){
            while(s[j]==' '){j--;if(j==-1){break;};}
            if(j==-1){break;}
            i=j;
            while(s[i]!=' '){i--;if(i==-1){break;};}
            x+=s.substr(i+1,j-i);
            x+=" ";
            if(i==-1){break;}
            j=i;
        }
        x.erase(x.size()-1,1);
        return x;
    }
};