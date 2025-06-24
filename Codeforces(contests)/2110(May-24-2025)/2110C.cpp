//https://codeforces.com/contest/2110/problem/C
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
    int n;
    cin>>n;
    int d[n];
    read(d,n);
    int l[n],r[n];
    fo(i,n){cin>>l[i]>>r[i];}
    int c=0,h=0,ic=0;
    vi v;
    bool found=true;
    fo(i,n){
        if((d[i]==0) || (d[i]==1)){
            h+=d[i];
            if(h>r[i]){found=false;break;}
            int j=r[i]-h;
            while(j<c && c>0){c--;ic++;}
            if(h<l[i]){
                if((h+c)>=l[i]){
                    int k=l[i]-h;
                    h=l[i];
                    c-=k;
                    while(k--){
                        d[v[ic]]=1;
                        // cout<<d[v[ic]]<<"\n";
                        ic++;
                    }
                }
                else{found=false;break;}
            }
        }
        else{
            d[i]=0;
            c++;
            v.pb(i);
            if(h>r[i]){found=false;break;}
            int j=r[i]-h;
            while(j<c && c>0){c--;ic++;}
            if(h<l[i]){
                if((h+c)>=l[i]){
                    int k=l[i]-h;
                    h=l[i];
                    c-=k;
                    while(k--){
                        d[v[ic]]=1;
                        // cout<<d[v[ic]]<<"\n";
                        ic++;
                    }
                }
                else{found=false;break;}
            }
        }
        // cout<<h<<d[i]<<c<<"\n";
    }
    if(found){
        print_space(d,n);
    }
    else{cout<<"-1\n";}
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