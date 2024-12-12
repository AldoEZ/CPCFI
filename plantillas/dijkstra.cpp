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

vll dijkstra(int v, int source, vector<vector<pll>>& adj) {
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

int main(){
    fastIO();
    int v, e; 
	cin >> v >> e; 
    vector<vector<pll>> adj(v+1);
	
	for(int i =  0; i < e; i++) {
		ll u,j,w;
		cin >> u >> j >> w;
		adj[u].push_back({j,w});
	}
	
    vll resp = dijkstra(v, 1, adj);
    for(int i = 1; i <= v; i++) {
        cout << resp[i] << " ";
    }
    cout << endl;
    return 0;
}
