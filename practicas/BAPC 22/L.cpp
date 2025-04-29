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

typedef array<ld,3> T;
void solve() {
	int n;cin >> n;
	vector<T> a(n);
	for(T &i:a)cin >> i[0] >> i[1] >> i[2];
	sort(all(a));
    
	auto dist = [&](int i,int j){
		T x = a[i], y = a[j];
		return sqrtl((x[0]-y[0])*(x[0]-y[0])+(x[1]-y[1])*(x[1]-y[1])+(x[2]-y[2])*(x[2]-y[2]));
	};
	ld ans = INF64;
	for(int i=0;i<n;i++){
		for(int j=i+1;abs(i-j)<=100 && j<n;j++){
			ans = min(ans,dist(i,j));
		}
	}
    
	cout << fixed << setprecision(12);
	cout << ans << '\n';
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
