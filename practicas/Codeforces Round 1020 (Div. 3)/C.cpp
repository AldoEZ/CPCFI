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
    int n, k; cin >> n >> k;
    vi a(n); for(int i = 0; i < n; i++) cin >> a[i];
    vi b(n);
    
    int sum = -1;
    bool no_buscados = 0;
    for(int j = 0; j < n; j++) {
        cin >> b[j];
        
        if(b[j] != -1) { no_buscados = 1; sum = b[j]+a[j]; }
    }
    
    if(no_buscados) {
        for(int i = 0; i < n; i++) {
            if(b[i] == -1) {
                int bi = sum - a[i];
                if(bi < 0 || bi > k) {
                    cout << 0 << '\n';
                    return;
                }
            } else {
                int sum_actual = b[i]+a[i];
                if(sum != sum_actual) {
                    cout << 0 << '\n';
                    return;
                }
            }
        }
        cout << 1 << '\n';
    } else {
        sort(all(a));
        cout << (k - (a[n-1] - a[0]) + 1) << '\n';
    }
}

int main(){
	fastIO();
	int tc = 1;
	cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
