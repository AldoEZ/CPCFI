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

int red(int x){
	if(x>=500)x-=100;
	return x;
}

void solve(){
	int a,b,c;
	cin >> a >> b >> c;
	int ans1 = a+b+c;
	ans1 = min(ans1,red(a)+red(b+c));
	ans1 = min(ans1,red(b)+red(a+c));
	ans1 = min(ans1,red(c)+red(a+b));
	ans1 = min(ans1,red(b+a+c));
	ans1 = min(ans1,red(a)+red(b)+red(c));
	cout << ans1 << '\n';
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++)solve();
}
