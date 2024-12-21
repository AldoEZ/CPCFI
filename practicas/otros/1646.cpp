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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int MOD = 1e9+7;
const int INF = INT_MAX;	
const ll INF64 = LLONG_MAX;		
const long double EPS = 1e-9;			
const long double PI = acosl(-1.0L);

void solve(){
    int n, q; cin >> n >> q;
    vll a(n); vll prefix(n);
    
    for(int i = 0; i < n; i++) cin >> a[i];
    
    prefix[0] = a[0];
    for(int j = 1; j < n; j++) prefix[j] += (prefix[j-1]+a[j]);
    
    for(int k = 0; k < q; k++) {
        int a, b; cin >> a >> b;
        
        if(a >= 2) cout << prefix[b-1] - prefix[a-2] << endl;
        else cout << prefix[b-1] << endl;
    }
}

int main(){
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++)solve();
}
