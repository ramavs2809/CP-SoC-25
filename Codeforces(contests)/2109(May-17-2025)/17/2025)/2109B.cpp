//https://codeforces.com/contest/2109/problem/B
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
void solve(){
    ull n,m,a,b,count,cmax=2000001;
    cin>>n>>m>>a>>b;
    int x[4],y[4];
    x[0]=a;y[0]=m;x[1]=n-a+1;y[1]=m;x[2]=n;y[2]=b;x[3]=n;y[3]=m-b+1;
    fo(i,4){
        count=1;
        n=x[i];m=y[i];
        a=(n+1)/2;b=(m+1)/2;
        while(n!=1 || m!=1){
            ull n1=0,m1=0,p=0;
            if(((a-1)*m)>p){p=(a-1)*m;n1=n-a+1;m1=m;}
            if((n*(b-1))>p){p=(n*(b-1));n1=n;m1=m-b+1;}
            if(((n-a)*m)>p){p=((n-a)*m);n1=a;m1=m;}
            if((n*(m-b))>p){p=(n*(m-b));n1=n;m1=b;}
            count+=1;
            a=(n1+1)/2;b=(m1+1)/2;
            n=n1;m=m1;
        }
        cmax=min(cmax,count);
    }
    cout<<cmax<<endl;
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
fastio;
int t;
cin>>t;
while(t--){
solve();
}
return 0;
}