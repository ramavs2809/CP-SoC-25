//https://codeforces.com/contest/2111/problem/C
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
vi f(11,0);
bool fpc(pii x,pii y){
    if(x.first!=y.first){return x.first<y.first;}
    else{return x.second<y.second;}
}
void solve(){
    int n;
    cin>>n;
    ll a[n];
    read(a,n);
    int c=1,i=0;
    ll x=a[i],best=INF;
    while(i<n){
        if(a[i+1]==x){c++;i++;}
        else{
            best=min(best,(x*(n-c)));
            c=1;x=a[i+1];i++;
        }
    }
    cout<<best<<"\n";
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
fastio;
int t=1;
cin>>t;
f[1]=1;f[2]=2;
fo1(i,3,11){
    f[i]=f[i-1]+f[i-2];
}
while(t--){
solve();
}
return 0;
}