//https://codeforces.com/contest/2118/problem/D1
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
    int n,k;
    cin>>n>>k;
    ll p[n];
    fo(i,n){
        cin>>p[i];
    }
    int d[n];
    read(d,n);
    int q;
    cin>>q;
    ll a[q];
    read(a,q);
    bool dir,loop;
    ll pos;
    int t,j,k1;
    set<tuple<ll,bool,int>> m;
    fo(i,q){
        dir=true;loop=true;
        pos=a[i];
        t=0;
        j=lower_bound(p,p+n,pos)-p;
        k1=upper_bound(p,p+n,pos)-p;
        if((j==k1)&&(j!=0)&&(j!=n)){
            t=(t+p[k1]-pos)%k;
            pos=p[k1];
            while(true){
                if((t%k)==d[k1]){dir=(!dir);}
                if((m.count({pos,dir,t})==1)){loop=false;break;}
                else{m.insert({pos,dir,t});}
                if(((k1==(n-1))&&dir)||((k1==0)&&!dir)){loop=true;break;}
                t=(t+((dir?(p[k1+1]-pos):(pos-p[k1-1]))))%k;
                k1+=(dir?1:-1);
                pos=p[k1];
                // cout<<pos<<"-";
            }
            m.clear();
        }
        else if((j==k1)&&((j==0)||(j==n))){loop=true;}
        else{
            if(true){
                t=0;
                pos=p[j];
                while(true){
                    if((t%k)==d[j]){dir=(!dir);}
                    if((m.count({pos,dir,t})==1)){loop=false;break;}
                    else{m.insert({pos,dir,t});}
                    if(((j==(n-1))&&dir)||((j==0)&&!dir)){loop=true;break;}
                    t=(t+((dir?(p[j+1]-pos):(pos-p[j-1]))))%k;
                    j+=(dir?1:-1);
                    pos=p[j];
                    // cout<<pos<<"-";
                }
                m.clear();
            }
        }
        YN(loop);
    }
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