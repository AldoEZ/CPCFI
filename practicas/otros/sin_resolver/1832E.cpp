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

const int MAX = 2e6;
ll factorial[MAX+1];
ll inv[MAX+1];

ll binpow(ll a,ll b) {
	ll ans = 1;
	a%=MOD;
	while(b){
		if(b&1)(ans*=a)%=MOD;
		(a*=a)%=MOD;
		b>>=1;
	}
	return ans;
}

void precalc() {
	factorial[0]=1;
	for (ll i = 1; i <= MAX; i++) {
		factorial[i] = factorial[i-1]*i%MOD;
	}
	inv[MAX] = binpow(factorial[MAX],MOD-2);
	for (ll i = MAX; i >= 1; i--) {
		inv[i-1] = inv[i]*i%MOD;
	}
}

ll ncr(ll a,ll b) {
	return factorial[a]*inv[b]%MOD*inv[a-b]%MOD;
}

void solve() {
    ll n,a1,x,y,m,k; cin >> n >> a1 >> x >> y >> m >> k;
    vll a; a.pb(a1);
    ll mod = 998244353;
    
    for(ll i = 1; i < n; i++) {
        ll ai = (a[i-1]*x+y)%m;
        a.pb(ai);
    }
    
    vll b;
    for(ll i = 0; i < n; i++) {
        ll bi = 0;
        for(ll j = 0; j <= i; j++) {
            ll xi = i-j+1;
            if(xi < k) break;
            
            ll comb = ncr(xi,k);
            bi += ((comb*a[j])%mod);
        }
        bi %= mod;
        b.pb(bi);
    }
    
    vll c;
    for(ll i = 0; i < n; i++) {
        ll ci = b[i]*(i+1);
        c.pb(ci);
    }
    
    ll ans = c[0];
    for(ll i = 1; i < n; i++) ans ^= c[i];
    
    cout << ans << '\n';
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
    precalc();
	for (int t = 1; t <= tc; t++) solve();
}
