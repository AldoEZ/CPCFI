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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    
    vector<vector<vi>> dp(k, vector<vi>(n, vi(n, 1e9)));
    
    for(int x = 0; x < k; x++) {
        for(int l = n-1; l >= 0; l--) {
            for(int r = 0; r < n; r++) {
                if(x == 0 && r >= l) { dp[x][l][r] = 0; continue; }
                if(x == 1 && r > l) { dp[x][l][r] = min({dp[x][l][r-1], dp[x][l+1][r], (s[l] != s[r]? 1 : 0)}); continue; }
                if(r-1 < 0 || l+1 == n || x-2 < 0) continue;
                dp[x][l][r] = min({dp[x][l][r-1], dp[x][l+1][r], dp[x-2][l+1][r-1] + (s[l] != s[r]? 1 : 0)});
            }
        }
    }
    cout << dp[k-1][0][n-1] << '\n';
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
