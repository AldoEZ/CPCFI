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

bool bfs(int start, vector<vi>& adj, vi& bfsA) {
    vector<bool> visited(sz(adj), 0);
    queue<int> q;
    bool f = 1; int i = 0;
    
    visited[start] = 1;
    q.push(start);
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        if(bfsA[i] != node) f = 0;
        i++;
        cout << node << " ";
        
        for(auto v : adj[node]) {
            if(!visited[v]) {
                visited[v] = 1;
                q.push(v);  
            }
        }
    }
    cout << '\n';
    return f;
}

void solve() {
    int n; cin >> n;
    vector<vi> adj(n+1);
    vi bfsA(n);
    for(int i = 1; i < n; i++) {
        int a,b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i = 0; i < n; i++) cin >> bfsA[i];
    bool BFS = bfs(1,adj,bfsA);
    
    if(BFS) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
