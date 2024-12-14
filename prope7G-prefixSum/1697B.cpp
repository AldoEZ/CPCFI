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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int MOD = 1e9+7;
const int INF = INT_MAX;	
const ll INF64 = LLONG_MAX;		
const long double EPS = 1e-9;			
const long double PI = acosl(-1.0L);

void solve(){
    ll n,q; cin >> n >> q;
    vi a(n);
	vll prefix(n);
    
    for(ll i = 0; i < n ; i++) cin >> a[i];
    sort(all(a));
	prefix[0] = a[n-1];
    
	for(ll i = 1; i < n; i++) prefix[i] = prefix[i-1] + a[n-i-1];
	
	for(ll i = 0; i < q; i++) {
		ll x,y; cin >> x >> y;
		if(x == y) cout << prefix[x-1] << endl;
		else cout << prefix[x-1] - prefix[x-y-1] << endl;
	}
}

int main(){
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++)solve();
}
