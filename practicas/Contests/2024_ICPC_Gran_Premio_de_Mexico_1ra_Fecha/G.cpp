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
    vi stones(n);
    string ans;
    int cnt = 1;
    
    for(int i = 0; i < n; i++) cin >> stones[i];
    
    sort(all(stones));
    stones.erase(unique(all(stones)), stones.end());
    
    if(stones[0] != 1) {
        cout << "Alicius" << '\n';
        return;
    }
    
    for(int i = 1; i < sz(stones); i++) {
        if(stones[i] >= stones[i-1]+2) break;
        cnt++;
    }
    
    if(cnt == sz(stones)) {
        if(cnt%2 == 0) ans = "Bobius";
        else ans = "Alicius";
    } else {
        if(cnt%2 == 0) ans = "Alicius";
        else ans = "Bobius";
    }
    cout << ans << '\n';
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
