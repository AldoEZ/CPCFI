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

vll dist;

vi dijkstra(ll v, int source, vector<vpii>& adj) {
    dist.resize(v+1, INF64);
    vi nodes(v+1, -1);
    priority_queue<pii, vpii, greater<pii>> pq;
    
    dist[source] = 0;
    pq.push({0, source});
    
    while(!pq.empty()) {
        int d = pq.top().F;
        int u = pq.top().S;
        pq.pop();
        
        if(d > dist[u]) continue;
        
        for(auto &edge : adj[u]) {
            int v = edge.F;
            int weight = edge.S;
            
            if(dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                nodes[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    return nodes;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vpii> adj(n+1);
    
    while(m--) {
        ll a, b, w;
        cin >> a >> b >> w;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }
    
    vi pa = dijkstra(n, 1, adj);
    if(dist[n] == INF64) { cout << -1 << '\n'; return; }
    
    vi ans; int i = n;
    while(i != 1) {
        ans.push_back(i);
        i = pa[i];
    } ans.pb(1);
    reverse(all(ans));
    
    for(auto i : ans) cout << i << " ";
    cout << '\n';
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
