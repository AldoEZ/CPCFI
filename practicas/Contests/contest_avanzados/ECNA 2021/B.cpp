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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pair<int,int>> vpii;
typedef vector<pair<ll,ll>> vpll;
const int MOD = 1e9+7;
const int INF = INT_MAX;	
const ll INF64 = LLONG_MAX;		
const long double EPS = 1e-9;			
const long double PI = acosl(-1.0L);

const int MAX = 1e3+5,LG=18;
vi deep(MAX);//Si tiene peso vi cost(MAX)
int par[MAX][LG+1];
int cnt = -1;
vll cost(MAX);
vector<vi> adj(MAX);

void dfs(int u = 1,int p=0){// U = raiz del arbol
	par[u][0] = p;
	deep[u] = deep[p]+1;
	cost[u] += cost[p];
	for(int i=1;i<=LG;i++)par[u][i]=par[par[u][i-1]][i-1];
	for(int v:adj[u]){
		if(v!=p){
			dfs(v,u);
		}
	}
}

int lca(int u,int v){
	if(deep[u] < deep[v])swap(u,v);
	for(int k=LG;k>=0;k--)
		if(deep[par[u][k]] >= deep[v])
			u = par[u][k];
	if(u==v)return u;
	for(int k=LG;k>=0;k--)
		if(par[u][k]!=par[v][k])
			u=par[u][k],v=par[v][k];
	return par[u][0];
}

ll dist(int u,int v){
	int lc = lca(u,v);
	return cost[u]+cost[v]-(cost[lc]);
}

void solve(){
	int n,m;
	cin >> n >> m;
    
	vi in(n+1,0);
	vi out(n+1,0);
	cost[1] = 0;
	for(int i=2;i<=n+1;i++)cin >> cost[i];
    
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		in[b]++;out[a]++;
		adj[a+1].pb(b+1);
	}
    
	for(int i=1;i<=n;i++){
		if(!in[i]){
			adj[1].pb(i+1);
		}
	}
    
	dfs();
    
	vi leaves;
	for(int i=1;i<=n;i++)if(!out[i])leaves.pb(i+1);
	ll ans = INF64;
    
	for(int i=0;i<sz(leaves);i++)
		for(int j=i+1;j<sz(leaves);j++)ans = min(ans,dist(leaves[i],leaves[j]));
    
	cout << ans << '\n';
	
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}