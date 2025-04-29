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

struct point{
	int x,y;
};

void solve(){
	int n;cin >> n;
	vector<point> a(n);
	for(point &i:a)cin >> i.x >> i.y;
    
	ld ans = -INF64;
    
	auto angle = [&](int s,int p){
		point start = a[s];
		point me = a[p];
        
		ld m = me.y-start.y;
		m/=(me.x-start.x);
		
		return abs(180*atan(m)/PI);
	};
    
	for(int i=1;i<n;i++){
		ans = max(ans,angle(0,i));
		ans = max(ans,angle(i-1,n-1));
	}
	
	cout <<fixed << setprecision(12) << ans << '\n';
}

int main(){
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
