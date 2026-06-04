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
const int MOD = 998244353;
const int INF = INT_MAX;	
const ll INF64 = LLONG_MAX;		
const long double EPS = 1e-9;			
const long double PI = acosl(-1.0L);

void setIO(string p){
	freopen((p + ".in").c_str(), "r", stdin);
	freopen((p + ".out").c_str(), "w", stdout);
}

vi z_function(string &s) {
    int n = s.size();
    vi z(n);
    int l = 0, r = 0;
    
    for (int i = 1; i < n; i++) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

void solve() {
    int n,k; cin >> n >> k;
    string s; cin >> s;
    
    vb can(n+1, 0); can[0] = 1;
    vi length, z = z_function(s);
    for(int i = 1; i <= n; i++) {
        for(auto l : length) {
            if(l > i) break;
            if(can[i-l] && z[i-l] >= l) {
                can[i] = 1;
                break;
            }
        }
        
        if(!can[i]) {
            can[i] = 1;
            length.pb(i);
        }
    }
    vi dp(k+1); dp[0] = 1;
    for(int i = 1; i <= k; i++) {
        for(auto l : length) {
            if(l <= i) {
                dp[i] += dp[i-l];
                dp[i] %= MOD;
            } else break;
        }
    }
    cout << dp[k] << '\n';
}

int main() {
	fastIO();
	int tc = 1;
	cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
