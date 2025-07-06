//https://codeforces.com/contest/2124/problem/E
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
    int n;
    cin>>n;
    ll a[n],sum=0,ma=0;
    fo(i,n){
        cin>>a[i];
        sum+=a[i];
        ma=max(ma,a[i]);
    }
    if(sum%2!=0){cout<<"-1\n";}
    else{
        sum/=2;
        if(ma>sum){cout<<"-1\n";}
        else{
            int i=0;
            ll s=0;
            while((s+a[i])<=sum){s+=a[i];i++;}
            if(s==sum){
                cout<<"1\n";
                print_space(a,n);
            }
            else{
                cout<<"2\n";
                fo(j,i){cout<<a[j]<<" ";a[j]=0;}
                ll rm=sum-a[i];
                cout<<s+a[i]-sum<<" ";a[i]=sum-s;i++;
                while(rm>0){
                    if(a[i]>=rm){a[i]-=rm;cout<<rm<<" ";i++;break;}
                    else{
                        rm-=a[i];
                        cout<<a[i]<<" ";
                        a[i]=0;
                        i++;
                    }
                }
                while(i<n){cout<<"0 ";i++;}
                cout<<"\n";
                print_space(a,n);
            }
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