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

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    
    bool check = 0;
    int cnt = 0;
    
    for(int i=0;i<n;i++) { if(s[i]=='W') cnt++; }
	if(cnt%2!=0) {
		cout<<"NO\n";
		return;
	}
	for(int i=0; i<cnt/2; i++) { if(s[i]=='R') check=1; }
	if(check) {
		cout<<"NO\n";
		return;
	}
	cnt = 0;
    
	for(int i=n*2-1; i>=n; i--) { if(s[i]=='R') cnt++; }
	if(cnt%2!=0) {
		cout<<"NO\n";
		return;
	}
	check=0;
	for(int i=n*2-1; i>=n*2-cnt/2; i--) { if(s[i]=='W')check=1; }
	if(check) {
		cout<<"NO\n";
		return;
	}
    
	cout<<"YES\n";
}

int main() {
	fastIO();
	int tc = 1;
	cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
