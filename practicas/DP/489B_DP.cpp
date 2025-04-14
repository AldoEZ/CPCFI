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
    vi boys(n);
    for(int i = 0; i < n; i++) cin >> boys[i];
    sort(all(boys));
    
    int m; cin >> m;
    vi girls(m);
    for(int j = 0; j < m; j++) cin >> girls[j];
    sort(all(girls));
    
    int dp[n][m];
    for(int b = 0; b < n; b++) {
        for(int g = 0; g < m; g++) {
            dp[b][g] = 0;
            if(b-1 >= 0 && g-1 >= 0) dp[b][g] = max(dp[b][g], dp[b-1][g-1]);
            if(abs(boys[b]-girls[g]) <= 1) dp[b][g]++;
            if(b-1 >= 0) dp[b][g] = max(dp[b][g],dp[b-1][g]);
            if(g-1 >= 0) dp[b][g] = max(dp[b][g],dp[b][g-1]);
        }
    }
    cout << dp[n-1][m-1] << '\n';
}

int main(){
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++)solve();
}
