//https://codeforces.com/contest/2111/problem/E
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define MOD 1000000007
#define DIV 998244353
#define INF 1e18
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pll pair<ll, ll>
#define v(x) vector<x>
#define fo(i, n) for (decltype(n) i = 0; i < n; i++)
#define re(i, n) for (decltype(n) i = n - 1; i >= 0; i--)
#define fo1(i, a, b) for (decltype(b) i = a; i < b; i++)
#define re1(i, a, b) for (decltype(a) i = a; i >= b; i--)
#define YN(possible) cout << ((possible) ? "YES" : "NO") << endl;
#define all(x) (x).begin(), (x).end()
#define sortall(x) sort(all(x))
#define F first
#define S second
#define pb push_back
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define read(a, n) for (int i = 0; i < n; ++i) cin >> a[i];
#define print_space(a, n) for (int i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? "\n" : " ");
bool fpc(pii x,pii y){
    if(x.first!=y.first){return x.first<y.first;}
    else{return x.second<y.second;}
}
void solve(){
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    int n1=0,n2=0,n1b=0,n2b=0,n1d=0,n2d=0,nb=0;
    char x,y;
    fo(i,q){
        cin>>x>>y;
        if((x=='b')&&(y=='a')){
            n1++;
            if(n2b>0){n2d++;n2b--;}
        }
        else if((x=='c')&&(y=='a')){
            n2++;
            if(n1b>0){n1d++;n1b--;}
        }
        else if((x=='b')&&(y=='c')){n1b++;}
        else if((x=='c')&&(y=='b')){n2b++;nb++;}
        else{}
    }
    fo(i,n){
        if(s[i]=='b'){
            if(n1>0){
                if(n1<=n2d){n2d--;}
                n1--;
                s[i]='a';
            }
            else if((n2>0)&&(n1d>0)){s[i]='a';n2--;n1d--;}
        }
        else if(s[i]=='c'){
            if(n2>0){
                s[i]='a';
                if(n2<=n1d){n1d--;}
                n2--;
            }
            else if((n1>0)&&(n2d>0)){s[i]='a';n1--;n2d--;nb--;}
            else if(nb>0){s[i]='b';nb--;}
        }
        // cout<<i<<endl;
    }
    cout<<s<<"\n";
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
fastio;
int t=1;
cin>>t;
while(t--){
solve();
}
return 0;
}