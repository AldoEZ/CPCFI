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
	string x,y;
	cin >> x >> y;
	
	auto t = [](string s){
		if(s == "N")return 90;
		if(s == "S")return 270;
		if(s == "W")return 180;
		if(s == "E")return 360;
		if(s == "NE")return 45;
		if(s == "SE")return 315;
		if(s == "SW")return 225;
		return 135;
	};
	
	auto calc = [](ld val,string x){
		string s = x.substr(sz(x)-2);
		int cnt = 0;
		if(s == "NE") {
			ld start = 45;
			for(int i=sz(x)-3;i>=0 && cnt<=29;i--,cnt++){
				start /=2;
				if(x[i] == 'N')val += start;
				else val -= start;
			}
			return val;
		}
		if(s == "SE") {
			ld start = 45;
			
			for(int i=sz(x)-3;i>=0 && cnt<=29;i--,cnt++) {
				start /=2;
				if(x[i] == 'S')val -= start;
				else val += start;
			}
			return val;
		}
		if(s == "SW") {
			ld start = 45;
			
			for(int i=sz(x)-3;i>=0 && cnt<=29;i--,cnt++){
				start /=2;
				if(x[i] == 'S')val += start;
				else val -= start;
			}
			return val;
		}
		ld start = 45;
		
		for(int i=sz(x)-3;i>=0 && cnt<=29;i--,cnt++) {
			start /=2;
			if(x[i] == 'N')val -= start;
			else val += start;
		}
		return val;
		
	};
	
	ld deg1 ,deg2;
	if(sz(x) == 1)deg1 = t(x);
	else deg1 = t(x.substr(sz(x)-2));
	if(sz(y) == 1)deg2 = t(y);
	else deg2 = t(y.substr(sz(y)-2));
	
	if(sz(x)>2)deg1 = calc(deg1,x);
	if(sz(y)>2)deg2 = calc(deg2,y);
	if(deg1 > deg2)swap(deg1,deg2);
	cout << fixed << setprecision(12) ;
	cout << min(deg2-deg1,ld(360)+deg1-deg2) << '\n';
}

int main(){
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
