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

void DFSRec(vector<vector<int>> &adj, vector<bool> &visited, int s) {
    visited[s] = true; 
    
    cout << s << " ";
    
    for (int i : adj[s])
        if (visited[i] == false) {
            DFSRec(adj, visited, i);
        }
}

void addEdge(vector<vector<int>> &adj, int s, int t){
    adj[s-1].push_back(t);
}

void solve() {
    int n, m=0;
    int n1, n2;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    
    for(int i = 1; i <= m; i++) {
        cin >> n1 >> n2;
        addEdge(adj,n1,n2);
    }
    
    vector<bool> visited(adj.size(), false);
    for(int i = 1; i <= n; i++) {
        if(visited[i] == false)
            DFSRec(adj, visited, i);
    }
}

int main() {
	fastIO();
	solve();
}
