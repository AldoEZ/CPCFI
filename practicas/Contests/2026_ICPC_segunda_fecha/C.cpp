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

ll binPow(ll a, ll b) {
    ll ans = 1;
    
    while(b) {
        if(b&1) (ans *= a) %= MOD;
        (a *= a) %= MOD;
        b >>= 1;
    }
    return ans;
}

void solve() {
    ll k; cin >> k;
    ll numerador = 1, denominador = 1;
    
    while(k--) {
        ll n;  cin >> n;
        ll aux;
        aux = (n-1)*(n-1);
        aux = floor(aux/4);
        aux = aux % MOD;
        numerador = numerador * aux % MOD;
        
        aux = n % MOD;
        aux = aux * ((n-1) % MOD) % MOD;
        aux = aux * ((n-2) % MOD) % MOD;
        aux = aux * binPow(6,MOD-2)%MOD;
        denominador = denominador * aux % MOD;
        
        ll arns = (numerador%MOD) * binPow(denominador, MOD-2)%MOD;
        cout << arns << '\n';
    }
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
