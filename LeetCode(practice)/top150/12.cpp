//https://leetcode.com/problems/integer-to-roman/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    string intToRoman(int num) {
        int a,a1,b,b1,c,d;
        string s="";
        a=num/1000;
        a1=a;
        while(a--){s.append("M");}
        b=num/100-10*(num/1000);
        b1=b;
        if(b==4){s.append("CD");}
        else if(b==9){s.append("CM");}
        else if(b<5){while(b--){s.append("C");}}
        else{s.append("D");while(b>5){s.append("C");b--;}}
        c=num/10-10*b1-100*a1;
        if(c==4){s.append("XL");}
        else if(c==9){s.append("XC");}
        else if(c<5){while(c--){s.append("X");}}
        else{s.append("L");while(c>5){s.append("X");c--;}}
        d=num%10;
        if(d==4){s.append("IV");}
        else if(d==9){s.append("IX");}
        else if(d<5){while(d--){s.append("I");}}
        else{s.append("V");while(d>5){s.append("I");d--;}}
        return s;
    }
};