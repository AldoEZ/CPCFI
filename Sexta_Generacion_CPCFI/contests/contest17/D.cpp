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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int MOD = 1e9+7;
const int INF = INT_MAX;	
const ll INF64 = LLONG_MAX;		
const long double EPS = 1e-9;			
const long double PI = acosl(-1.0L);

void solve(){
    ll n; cin >> n;
    vll a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    
    auto min_aux = min_element(all(a));
    auto max_aux = max_element(all(a));
    
    ll min = min_aux[0];
    ll max = max_aux[0];
    ll cont_min = 0;
    ll cont_max = 0;
    
    sort(a.begin(), a.end());
    
    for(ll i = 0; i < n; i++) {
        if(a[i] == min) cont_min++;
        if(a[i] == max) cont_max++;
    }
    
    if(a[0] == a[a.size() - 1]) {
        cout << cont_min*(cont_max-1) << endl;
    } else {
        cout << cont_max*cont_min*2 << endl;
    }
}

int main(){
	fastIO();
	int tc = 1;
	cin >> tc;
	for (int t = 1; t <= tc; t++)solve();
}
