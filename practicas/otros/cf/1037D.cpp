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

vi nOrd;
bool pos(int a, int b) {
    return nOrd[a] < nOrd[b];
}

vi bfs(int start, vector<vi>& adj) {
    vector<bool> visited(sz(adj), 0);
    queue<int> q;
    vi ans;
    
    visited[start] = 1;
    q.push(start);
    
    while(!q.empty()){
        queue<int> temp;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.pb(node);
            visited[node] = 1;
            
            for(auto v : adj[node])
                if(!visited[v])
                    temp.push(v);
        }
        q = temp;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<vi> adj(n+1);
    vi bfsA(n);
    nOrd.resize(n+1);
    for(int i = 1; i < n; i++) {
        int a,b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i = 0; i < n; i++) {
        cin >> bfsA[i];
        nOrd[bfsA[i]] = i;
    }
    for(int i = 1; i <= n; i++) sort(all(adj[i]), pos);
    
    vi ans = bfs(1,adj);
    
    for(int i = 0; i < n; i++) {
        if(bfsA[i] != ans[i]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
