//https://www.hackerrank.com/contests/iitb-2025-26-mock-coding-test-1/challenges/qheap1
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q;
    cin>>q;
    map<int,int> m;
    while(q--){
        int c,a;
        cin>>c;
        if((c==1)||(c==2)){cin>>a;}
        if(c==1){
            m[a]++;
        }
        else if(c==2){
            m[a]--;
        }
        else{
            for(auto j : m){
                if(j.second>0){cout<<j.first<<"\n";break;}
            }
        }
    }
    return 0;
}