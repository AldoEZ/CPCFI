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
	int n,a,b; cin >> n >> a >> b;
	string s; cin  >> s;
	
	pii poss = {0,0};
	int i = 0;
	
	while(poss.F <= a || poss.S <= b) {
		if(i == n) i = 0;
		
		if(s[i] == 'N') poss.S++;
		else if(s[i] == 'S') poss.S--;
		else if(s[i] == 'E') poss.F++;
		else if(s[i] == 'W') poss.F--;
		
		if(poss.F == a && poss.S == b) {
			cout << "YES" << endl;
			return;
		}
		i++;
	}
	cout << "NO" << endl;
}

int main(){
	fastIO();
	int tc = 1;
	cin >> tc;
	for (int t = 1; t <= tc; t++)solve();
}
