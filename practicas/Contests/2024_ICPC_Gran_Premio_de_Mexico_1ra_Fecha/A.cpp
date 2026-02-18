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
    int n; cin >> n;
    vi numbers(n);
    for(auto &i : numbers) cin >> i;
    
    vector<vi> dp(n, vi(n,INF));
    for(int i = n-2; i >= 0; i--) {
        for(int j = 0; j < n; j++) {
            if(j <= i) continue;
            dp[i][j] = min({dp[i+1][j], dp[i][j-1], abs(numbers[i]-numbers[j])});
        }
    }
    
    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        cout << dp[l-1][r-1] << '\n';
    }
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
