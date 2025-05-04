#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
const ll INF64 = LLONG_MAX;

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
