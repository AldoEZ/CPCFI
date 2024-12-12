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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int MOD = 1e9+7;
const int INF = INT_MAX;	
const ll INF64 = LLONG_MAX;		
const long double EPS = 1e-9;			
const long double PI = acosl(-1.0L);

vll prim(vector<vector<pll>>& adj, ll v, ll source) {
	vll weights(v+1, INF64);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    
    pq.push({0, source});
    
    while(!pq.empty()) {
        ll d = pq.top().F;
        ll u = pq.top().S;
        pq.pop();
        
        if(d > weights[u]) continue;
        
        for(auto &edge : adj[u]) {
            ll v = edge.F;
            ll weight = edge.S;
            
            if(weights[u] + weight < weights[v]) {
                weights[v] = weights[u] + weight;
                pq.push({weights[v], v});
            }
        }
    }
    return weights;
}

void solve(){
    ll n, m; cin >> n >> m;
    vector<vector<pll>> adj(n+1);
	
	if(m-1 < n) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
    
    for(int i =  0; i < m; i++) {
        ll a, b, c;
		cin >> a >> b >> c;
		adj[a].pb({b,c});
        adj[b].pb({a,c});
	}
	
}

int main(){
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++)solve();
}