//https://codeforces.com/contest/2120/problem/C
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
    ll n,m;
    cin>>n>>m;
    if((m<n)||(m>((n*(n+1))/2))){cout<<"-1\n";}
    else{
        ll a=n,b=n;
        int com[n];
        fill_n(com,n,0);
        while(a>0){
            if((a+(n-1))<=m){cout<<a<<"\n";m-=a;com[a-1]=1;break;}
            else{a--;}
        }
        ll c=n-2;
        while(b>1){
            if(com[b-1]==0){
                if(m>=(b+c)){cout<<b<<" "<<a<<"\n";a=b;com[b-1]=1;m-=b;c--;}
            }
            b--;
            if((b==1)&&(a!=1)){cout<<b<<" "<<a<<"\n";com[b-1]=1;}
        }
        fo(i,n){
            if(com[i]==0){cout<<i+1<<" 1\n";}
        }
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