#include <bits/stdc++.h>

using namespace std;

#define fastIO() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()		
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
    string s; cin >> s;
    
    bool tb=0,ab=0,pb=0;
    int t,a;
    for(int i = 0; i < sz(s); i++) if(s[i] == 'T') if(s[i] == 'T') { tb=1; t=i; break; }
    for(int i = t+1; i < sz(s); i++) if(s[i] == 'A') if(s[i] == 'A') { ab=1; a=i; break; }
    for(int i = a+1; i < sz(s); i++) if(s[i] == 'P') if(s[i] == 'P') { pb=1; break; }
    
    if(tb && ab && pb) cout << 'S' << '\n';
    else cout << 'N' << '\n';
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
