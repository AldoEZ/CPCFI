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

void solve(){
	int n;
	cin >> n;
	vi deg(n,0);
	vector<vi> adj(n);
	for(int i=1;i<n;i++){
		int u,v;
		cin >> u >> v;
		deg[--u]++;
		deg[--v]++;
		adj[u].pb(v);
		adj[v].pb(u);
	}
    
	queue<int> q;
	vector<bool> vis(n,0);
	vi dis(n,INF);
	for(int i=0;i<n;i++)
		if(deg[i]==1){
			q.push(i);
			vis[i] = 1;
			dis[i] = 0;
		}
    
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v:adj[u]){
			if(!vis[v]){
				dis[v] = min(dis[v],dis[u]+1);
				q.push(v);
				vis[v]=1;
			}
		}
	}
	cout << max_element(all(dis))-dis.begin()+1 << '\n';
	
}

int main(){
	fastIO();
	int tc = 1;
	cin >> tc;
	for (int t = 1; t <= tc; t++)solve();
}
