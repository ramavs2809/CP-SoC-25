//https://cses.fi/problemset/task/1746
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
#define INF 1e18
#define DIV 998244353
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
#define pb push_back
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define read(a, n) for (int i = 0; i < n; ++i) cin >> a[i];
#define print_space(a, n) for (int i = 0; i < n; ++i) cout << a[i] << (i == n - 1 ? "\n" : " ");
void solve(){
    int n,m;
    cin>>n>>m;
    int x[n];
    read(x,n);
    ll c[n][m+1];
    fo(i,n){
        fo(j,m+1){c[i][j]=0;}
    }
    if(x[0]==0){
        fo(i,m){c[0][i+1]=1;}
    }
    else{c[0][x[0]]=1;}
    fo1(j,1,n){
        if(x[j]==0){
            fo(i,m){
                c[j][i+1]+=c[j-1][i+1];
                if(i>=1){c[j][i+1]+=c[j-1][i];}
                if(i<=(m-2)){c[j][i+1]+=c[j-1][i+2];}
                c[j][i+1]%=MOD;
            }
        }
        else{
            c[j][x[j]]+=c[j-1][x[j]];
            if(x[j]>=2){c[j][x[j]]+=c[j-1][x[j]-1];}
            if(x[j]<=(m-1)){c[j][x[j]]+=c[j-1][x[j]+1];}
            c[j][x[j]]%=MOD;
        }
    }
    int count=0;
    fo(i,m){
        count+=c[n-1][i+1];
        count%=MOD;
    }
    cout<<count<<"\n";
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
fastio;
int t=1;
// cin>>t;
while(t--){
solve();
}
return 0;
}