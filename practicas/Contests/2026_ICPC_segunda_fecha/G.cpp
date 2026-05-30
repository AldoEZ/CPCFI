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

void setIO(string p){
	freopen((p + ".in").c_str(), "r", stdin);
	freopen((p + ".out").c_str(), "w", stdout);
}

void dfs(vector<vi> &g, vb &vis, int idx, vector<vi> &dsu, int ola) {
    vis[idx] = 1;
    dsu[ola].push_back(idx);
    
    for(auto &it : g[idx]) {
        if(!vis[it]) dfs(g, vis, it, dsu, ola);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    
    vector<vi> g(n);
    vb vis(n, 0);
    
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    int cnt = 0;
    vector<vi> dsu(n);
    
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(g, vis, i, dsu, cnt);
            cnt++;
        }
    }
    priority_queue<pii> pq;
    for(int i = 0; i < cnt; i++) {
        int tam = sz(dsu[i]);
        pq.push({tam, i});
    }
    
    vpii pares;
    
    while(!pq.empty()) {
        if(sz(pq) <= 1) break;
        
        auto [tam1,idx1] = pq.top();
        pq.pop();
        auto [tam2,idx2] = pq.top();
        pq.pop();
        
        int a = dsu[idx1].back();
        dsu[idx1].pop_back();
        int b = dsu[idx2].back();
        dsu[idx2].pop_back();
        
        pares.pb({a,b});
        tam1--; tam2--;
        
        if(tam1 > 0) pq.push({tam1, idx1});
        if(tam2 > 0) pq.push({tam2, idx2});
    }
    int arns = sz(pares);
    
    cout << arns << '\n';
    for (int i = 0; i < arns; i++) {
        cout << pares[i].F << " " << pares[i].S << '\n';
    }
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
