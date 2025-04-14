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
    int n; cin >> n;
    
    cout << 0 << '\n';
    if(n >= 2) cout << 6 << '\n';
    
    ll residuo = 0;
    for(int k = 3; k <=n; k++) {
        ll ans;
        if(k%2 == 0) {
            ans = ncr(k*k,2)-(k*k+residuo);
            residuo += (k*k);
        }
        else {
            ans = ncr(k*k,2)-(k*k-1+residuo);
            residuo += (k*k-1);
        }
        cout << ans << '\n';
    }
}

int main(){
	fastIO();
	int tc = 1;
	//cin >> tc;
    precalc();
	for (int t = 1; t <= tc; t++)solve();
}
