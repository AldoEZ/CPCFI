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

ll solve() {
    int n, k; cin >> n >> k;
    vll a(n);
    
    for(int i = 0; i <  n; i++) cin >> a[i];
    sort(all(a));
    
    ll sum = 0;
    
    for(int i = n-1; i >= 0 && i >= k-1; i--) {
        sum += (a[i] * ncr(i, k-1))%MOD;
    }
    return sum;
}

int main() {
	fastIO();
	int tc = 1;
    precalc();
	cin >> tc;
	for (int t = 1; t <= tc; t++){ 
        ll sol = solve();
        cout << "Case #" << t << ": " << sol << "\n";
    }
}
