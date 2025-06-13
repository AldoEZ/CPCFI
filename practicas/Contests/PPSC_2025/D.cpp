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

void solve(){
	int n;cin >> n;
	vi a(n-1);
	int mx = 0;
	for(int &i:a)cin >> i,mx =max(i,mx);
	vi cnt(mx+1,0);
	cnt[0] = 1;
    
	auto binpow = [&](ll a, ll b)->ll{
		ll res = 1;
		while(b){
			if(b&1)res=res*a%MOD;
			a =a*a%MOD;
			b>>=1;
		}
		return res;
	};
	
	for(int i=0;i<n-1;i++)cnt[a[i]]++;
	ll ans = 1;
	for(int i=1;i<=mx;i++){
		ans =ans*binpow(cnt[i-1],cnt[i])%MOD;
	}
	cout << ans << '\n';
}

int main(){
	fastIO();
	int tc = 1;
	cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
