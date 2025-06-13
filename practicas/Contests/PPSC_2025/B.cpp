#include <bits/stdc++.h>

using namespace std;

#define fastIO() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()	
#define pb push_back				
#define sz(a) int(a.size())				
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
const int MOD = 1e9+7;
const int INF = INT_MAX;	
const ll INF64 = LLONG_MAX;		
const long double EPS = 1e-9;			
const long double PI = acosl(-1.0L);

ll sumaTotalN(ll n){
    return n*(n+1)*(2*n+1) / 6;
}

void solve(){
    ll n; cin >> n;
    ll l=1,r=2e6,ans=0;
    while(l<=r){
        ll mid=(l+r)/2;
        if(sumaTotalN(mid) < n){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    ll total = ans*(ans+1)/2;
    ll res = n-sumaTotalN(ans);
    ll ex = (res+(ans+1)-1)/(ans+1);
    cout << total+ex << endl;
}

int main() {
    fastIO();
    int t = 1;
    cin >> t;
    for(int i = 0; i < t; i++)solve();
    return 0;
}
