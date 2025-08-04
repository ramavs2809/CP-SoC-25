//https://leetcode.com/problems/zigzag-conversion/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if((n<=numRows)||(numRows==1)){return s;}
        else{
            string x="";
            int j=0;
            vector<int> v;
            while(j<(n+numRows)){v.push_back(j);j+=(2*numRows-2);}
            for(int i=0;i<numRows;i++){
                j=i;
                if((i==0)||(i==numRows-1)){
                    while(j<n){x+=s[j];j+=(2*numRows-2);}
                }
                else{
                    int k;
                    k=v[0]+i;
                    x+=s[k];
                    for(int l=1;l<v.size();l++){
                        k=v[l]-i;
                        if(k<n){x+=s[k];}
                        k=v[l]+i;
                        if(k<n){x+=s[k];}
                    }
                }
            }
            return x;
        }
    }
};