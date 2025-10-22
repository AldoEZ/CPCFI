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

void solve() {
    int N, C, T1, T2; cin >> N >> C >> T1 >> T2;
    vi F(N*2);
    for(int i = 0; i < N; i++) cin >> F[i];
    for(int i = N; i < 2*N; i++) F[i] = F[i-N]+C;
    
    vi sigT1(N*2), sigT2(N*2);
    for(int i = 0; i < 2*N; i++) {
        sigT1[i] = upper_bound(all(F), F[i]+T1) - F.begin();
        sigT2[i] = upper_bound(all(F), F[i]+T2) - F.begin();
        cout << sigT1[i] << " " << sigT2[i] << '\n';
    }
    cout << '\n';
    ll ans = INF64;
    vll dp(N*2+1, 0);
    for(int i = 0; i < N; ++i) {
        for(int j = i+N-1; j >= i; --j) {
            ll t1 = T1 + (sigT1[j] > i+N? 0 : dp[sigT1[j]]);
            ll t2 = T2 + (sigT2[j] > i+N? 0 : dp[sigT2[j]]);
            cout << t1 << ' ' << t2 << '\n';
            dp[j] = min(t1,t2);
        }
        cout << '\n';
        ans = min(ans,dp[i]);
    }
    cout << ans << '\n';
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
