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

void solve() {
    int n; cin >> n;
    vi par; vi impar;
    
    for(int i = 1; i <= n; i++) {
        if(i%2 == 0) par.pb(i);
        else impar.pb(i);
    }
    
    if(n == 1) cout << 1 << '\n';
    else if(n == 2 || n == 3) cout << "NO SOLUTION" << '\n';
    else {
        for(int i = 0; i < sz(par); i++) cout << par[i] << " ";
        for(int j = 0; j < sz(impar); j++) cout << impar[j] << " ";
    }
    cout << '\n';
}

int main(){
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++)solve();
}
