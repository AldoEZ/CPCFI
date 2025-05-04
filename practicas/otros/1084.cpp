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
typedef long double ld;
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
    ll n,m,k; cin >> n >> m >> k;
    vll a(n), b(m);
    for(ll &i : a) cin >> i; sort(all(a));
    for(ll &j : b) cin >> j; sort(all(b));
    
    ll i = 0, j = 0, ans = 0;
    while(i < n && j < m) {
        if(((a[i]+k) >= b[j]) && ((a[i]-k) <= b[j])) {
            ans++; i++; j++; 
        } else {
            if(a[i]+k < b[j]) i++;
            else j++;
        }
    }
    cout << ans << '\n';
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
