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

void solve(){
    int n; cin >> n;
    vi a(n);
    
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    
    int x = n-2, y = n-1;
    vpii parejas;
    while(x != y) {
        cout << "Conversaciones: " << a[x] << " " << a[y] <<endl;
        cout << "indices: " << x << " " << y << endl;
        if(a[x] > 0 && a[y] > 0) {
            parejas.pb({x+1, y+1});
            a[x]--; a[y]--;
        }
        if(a[x] == 0) x--;
        if(a[y] == 0) y--;
    }
    
    int sn = sz(parejas);
    cout << sn << endl;
    for(int i = 0; i < sn; i++) cout << parejas[i].F << " " << parejas[i].S << endl;
}

int main(){
	fastIO();
	int tc = 1;
	cin >> tc;
	for (int t = 1; t <= tc; t++)solve();
}
