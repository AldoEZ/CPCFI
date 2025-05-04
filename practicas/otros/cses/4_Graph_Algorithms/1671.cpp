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

vll dijkstra(ll v, ll source, vector<vpll>& adj) {
    vll dist(v+1, INF64);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    
    dist[source] = 0;
    pq.push({0, source});
    
    while(!pq.empty()) {
        ll d = pq.top().F;
        ll u = pq.top().S;
        pq.pop();
        
        if(d > dist[u]) continue;
        
        for(auto &edge : adj[u]) {
            ll v = edge.F;
            ll weight = edge.S;
            
            if(dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

void solve() {
    ll n, m; cin >> n >> m;
    
    vector<vpll> adj(n+1);
    
    for(int i = 0; i < m; i++) {
        ll a,b,c; cin >> a >> b >> c;
        adj[a].pb({b,c});
    }
    
    vll ans = dijkstra(n, 1, adj);
    for(int i = 1; i < sz(ans); i++) cout << ans[i] << " ";
    cout << '\n';
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
