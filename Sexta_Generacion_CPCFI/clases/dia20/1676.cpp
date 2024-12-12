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

vi pa;
vi sz;
int tc;int mc;

int get(int x){
	cout << x << " " << pa[x] << endl;
    return((pa[x] == x) ? x : pa[x] = get(pa[x]));
}

void unite(int a, int b){
    a = get(a);
	b = get(b);
    if(a == b) return;
	
    if(sz[a] > sz[b]) {
		int c = a;
		a = b;
		b = c;
	}
    pa[a] = b;
	sz[b] += sz[a];
    tc--;
	if(sz[b] > mc) mc = sz[b];
	
    return;
}

int main(){
    int n,m;
    cin >> n >> m;
    tc = n;
	mc = 1;
    for(int i = 0; i < n; i++) {
		pa.push_back(i);
		sz.push_back(1);
	}
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        unite(a-1,b-1);
        cout << tc << " " << mc << "\n";
    }
    return(0);
}
