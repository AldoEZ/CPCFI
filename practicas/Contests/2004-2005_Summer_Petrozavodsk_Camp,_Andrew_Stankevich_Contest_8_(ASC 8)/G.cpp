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

void solve() {
    int n; cin >> n;
    
    int maxLenght = ceil(sqrt(n));
    vi ans;
    
    int cnt1 = n, cnt2 = n-maxLenght+1, bloques = (n+maxLenght-1)/maxLenght;
    for(int i = 1; i <= bloques-1; i++) {
        for(int j = cnt2; j <= cnt1; j++) ans.pb(j);
        
        cnt1 = cnt2-1;
        cnt2 -= maxLenght;
    }
    
    if(bloques == maxLenght) {
        for(int i = 1; i <= cnt1; i++) ans.pb(i);
    } else {
        for(int i = 2; i <= cnt1; i++) ans.pb(i);
        ans.pb(1);
    }
    
    reverse(all(ans));
    for(auto i : ans) cout << i << " ";
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
    //setIO("perm");
    solve();
}
