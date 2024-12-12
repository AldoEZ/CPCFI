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

ll magic(vector<vll> &a, int i, int j, int n) {
    ll count = 0;
    for(int k = i; k < n; k++) {
        if(a[k][j] < count) {
            count = a[k][j];
            a[k][j] = 1;
        } else if(a[k][j] == count) a[k][j] = 1;
        j++;
    }
    cout << "count " << count << endl;
    return abs(count);
}

void solve(){
    int n; cin >> n;
    
    vector<vll> a(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ll aux; cin >> aux;
            
            a[i].pb(aux);
        }
    }
    ll count = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] < 0) {
                count += magic(a,i,j,n);
            }
        }
    }
    cout << count << endl;
}

int main(){
	fastIO();
	int tc = 1;
	cin >> tc;
	for (int t = 1; t <= tc; t++)solve();
}
