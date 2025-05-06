#include <bits/stdc++.h>

using namespace std;

#define pb push_back
typedef long long ll;
typedef vector<ll> vll;

vll nodesDfs;

void dfs(ll node, vector<vll>& adj, vector<bool>& visited) {
    visited[node] = 1;
    nodesDfs.pb(node);
    
    for(auto v : adj[node])
        if(!visited[v]) 
            dfs(v, adj, visited);
}
