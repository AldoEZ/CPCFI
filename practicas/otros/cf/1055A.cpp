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
    int n,s; cin >> n >> s;
    vi e1(n), e2(n);
    
    for(auto &i : e1) cin >> i;
    for(auto &j : e2) cin >> j;
    
    bool f = 1;
    if(!e1[0] || (!e1[s-1] && !e2[s-1])) f = 0;
    else if(e1[0] && !e1[s-1]) {
        for(int i = s; i < n; i++) {
            if(e1[i] && e2[i]) { f = 1; break; }
            f = 0;
        }
    }
    
    cout << (f? "YES" : "NO") << '\n';
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
