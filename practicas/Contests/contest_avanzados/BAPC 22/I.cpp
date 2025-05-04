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

struct Conversion {
    string target;
    ld factor;
};

unordered_map<string, vector<Conversion>> graph;

long double bfs(string& from,string& to) {
    if(from == to) return 1.0;
    queue<pair<string,ld>> q;
    unordered_map<string,bool> visited;
    q.push({from,1.0});
    visited[from]=true;
    while(!q.empty()){
        auto current=q.front();
        q.pop();
        for(auto& conver : graph[current.first]){
            if(conver.target == to){
                return current.second * conver.factor;
            }
            if(!visited[conver.target]){
                visited[conver.target]=true;
                q.push({conver.target,current.second*conver.factor});
            }
        }
    }
    return -1.0L;
}

void solve() {
    ll n,q; cin >> n >> q;
    for(int i=0;i<n;i++){
        string uno, from, igual, to;
        ld valor;
        cin >> uno >> from >> igual >> valor >> to;
        graph[from].pb({to,valor});
        graph[to].pb({from, 1.0 / valor});
    }
    for(int i=0;i<q;i++) {
        ld val; 
        string from, unit, to; cin >> val >> from >> unit >> to;
        ld conversion = bfs(from,to);
        if(conversion < 0){
            printf("impossible\n");
        } else {
            ld sol=val*conversion;
            printf("%.12Le\n",sol);
        }
    }
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
