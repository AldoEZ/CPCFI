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

multiset<ll> ms;
void update(queue<pll> &q){
	while(!q.empty()){
		auto [x,y] = q.front();
		q.pop();
		x==1?ms.insert(y):ms.erase(ms.find(y));
	}
}

void solve(){
	int n;cin >> n;
	vector<queue<pll>> a(n+1);
	vll dp(n+1,0);
    
	for(int i=1;i<=n;i++){
		update(a[i-1]);
		if(!ms.empty())dp[i] = *ms.rbegin();
		int g,x,y;
		cin >> g >> x >> y;
		dp[i]+=g;
		if(i+x > n)continue;
        
		a[i+x-1].emplace(1,dp[i]);
		a[min(i+y,n)].emplace(0,dp[i]);
	}
    
	ll ans = 0;
	for(ll i:dp)ans = max(ans,i);
	cout << ans << '\n';
}

int main(){
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++)solve();
}