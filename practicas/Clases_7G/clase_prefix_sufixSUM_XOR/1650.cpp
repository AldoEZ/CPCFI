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
    int n,q; cin >> n >> q;
    
    vll arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    vll prefix_xor(n+1,0);
    
    for(int i = 1; i <= n; i++) prefix_xor[i] = prefix_xor[i-1] ^ arr[i-1];
    
    for(int j = 0; j < q; j++) {
        int a, b; cin >> a >> b;
        
        cout << (prefix_xor[b] ^ prefix_xor[a-1]) << '\n';
    }
}

int main(){
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++)solve();
}
