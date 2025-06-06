// cses
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

vll pa, tam;
ll tco, mc;

ll get(ll a) {
    return ((pa[a] == a)? a : pa[a] = get(pa[a]));
}

void unite(ll a, ll b) {
    a = get(a);
    b = get(b);
    
    if(a == b) return;
    if(tam[a] > tam[b]) swap(a,b);
    
    tco--;
    pa[a] = b;
    tam[b] += tam[a];
    
    if(tam[b] > mc) mc = tam[b];
    return;
}

void solve() {
    ll n, m; cin >> n >> m;
    
    for(int i = 0; i < n; i++) pa.pb(i),tam.pb(1);
    tco = n, mc = 1;
    
    while(m--) {
        ll a,b; cin >> a >> b;
        unite(a-1,b-1);
        cout << tco << " " << mc << '\n';
    }
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
