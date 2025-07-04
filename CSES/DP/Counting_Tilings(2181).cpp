//https://cses.fi/problemset/task/2181
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
    int n1=pow(2,n);
    int c[m][n1];
    fo(i,m){
        fo(j,n1){c[i][j]=0;}
    }
    vi v;
    fo(i,n1){
        bool b=true;
        fo(j,n){
            if((i&(1<<j))==0){b=!b;}
            else{
                if(!b){break;}
            }
        }
        if(b){c[0][i]=1;v.pb(i);}
    }
    fo1(i,1,m){
        if(i!=(m-1)){
            fo(j,n1){
                fo(k,v.size()){
                    if(((j&(v[k]-j))==0)&&((v[k]-j)>=0)){c[i][j]+=c[i-1][(v[k]-j)];c[i][j]%=MOD;}
                }
            }
        }
        else{
            fo(k,v.size()){
                c[i][0]+=c[i-1][v[k]];c[i][0]%=MOD;
            }
        }
    }
    cout<<c[m-1][0]<<"\n";
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