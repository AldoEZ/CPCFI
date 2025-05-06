#include <bits/stdc++.h>

using namespace std;

#define pb push_back
typedef long long ll;
typedef vector<ll> vll;

vll topoSort;

void topoSortUtil(int node, vector<vll>& adj, vector<bool>& visited, stack<ll>& st) {
    visited[node] = 1;
    
    for(auto v : adj[node])
        if(!visited[v])
            topoSortUtil(v,adj,visited,st);
    
    st.push(node);
}

void topologicalSort(ll n, vector<vll>& adj) {
    stack<ll> st;
    vector<bool> visited(n,0);
    
    for(ll i = 0; i < n; i++)
        if(!visited[i])
            topoSortUtil(i,adj,visited,st);
    
    while(!st.empty()) {
        topoSort.pb(st.top());
        st.pop();
    }
}
