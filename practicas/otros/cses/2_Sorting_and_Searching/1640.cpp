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
    ll n, x; cin >> n >> x;
    
    vpll a;
    for(int i = 0; i < n; i++) {
        ll ai; cin >> ai;
        if(ai < x) a.pb({ai,i+1});
    }
    sort(all(a));
    
    ll i = 0, j = sz(a)-1;
    while(j-i > 0) {
        if(a[j].F+a[i].F < x) i++;
        else if(a[j].F+a[i].F > x) j--;
        else if(a[j].F+a[i].F == x) {
            if(a[i].S < a[j].S) cout << a[i].S << " " << a[j].S << '\n'; 
            else if(a[j].S < a[i].S) cout << a[j].S << " " << a[i].S << '\n'; 
            return; 
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}

int main(){
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++)solve();
}
