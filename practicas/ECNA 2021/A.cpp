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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pair<int,int>> vpii;
typedef vector<pair<ll,ll>> vpll;
const int MOD = 1e9+7;
const int INF = INT_MAX;	
const ll INF64 = LLONG_MAX;		
const long double EPS = 1e-9;			
const long double PI = acosl(-1.0L);

void solve(){
	int n;cin >> n;
    
	vll dp(n+1);
	iota(all(dp),0);
    
	auto _ = [](int j){
		int cnt = 1;
		while(j){
			cnt*=10;
			j/=10;
		}
		return cnt;
	};
    
	for(int i=0;i<=n;i++)
		for(int j=1;j<=min(n,int(1e4));j++){
			ll v1 = i+j;
			if(v1<=n)dp[v1] = min(dp[v1],dp[i]+dp[j]);
			v1 = 1ll*i*j;
			if(v1<=n)dp[v1] = min(dp[v1],dp[i]+dp[j]);
			v1 = 1ll*i*_(j)+j;
			if(v1<=n)dp[v1] = min(dp[v1],dp[i]+dp[j]);
		}
	
	cout << dp[n] << '\n';
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
