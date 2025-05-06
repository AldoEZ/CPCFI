#include <bits/stdc++.h>

using namespace std;

#define pb push_back				
#define sz(a) int(a.size())
typedef long long ll;
typedef vector<ll> vll;

vll nodesBfs;

void bfs(ll start, vector<vll>& adj) {
    vector<bool> visited(sz(adj), 0);
    queue<ll> q;
    
    visited[start] = 1;
    q.push(start);
    
    while(!q.empty()) {
        ll node = q.front();
        q.pop();
        nodesBfs.pb(node);
        
        for(auto v : adj[node]) {
            if(!visited[v]) {
                visited[v] = 1;
                q.push(v);  
            }
        }
    }
}
