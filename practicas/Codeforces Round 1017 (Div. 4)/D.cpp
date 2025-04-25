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
    string p,s;
    cin >> p; cin >> s;
    
    int np = sz(p), ns = sz(s);
    
    vector<pair<char,int>> Pi;
    char ref = p[0];
    int cont = 1;
    for(int i = 1; i < np; i++) {
        if(p[i] == ref) cont++;
        else {
            Pi.pb({ref,cont});
            ref = p[i];
            cont = 1;
        }
    }
    Pi.pb({ref,cont});
    
    vector<pair<char,int>> Sl;
    ref = s[0];
    cont = 1;
    for(int j = 1; j < ns; j++) {
        if(s[j] == ref) cont++;
        else {
            Sl.pb({ref,cont});
            ref = s[j];
            cont = 1;
        }
    }
    Sl.pb({ref, cont});
    
    np = sz(Pi), ns = sz(Sl);
    if(np != ns) cout << "NO" << '\n';
    else {
        for(int i = 0; i < np; i++) {
            if(Pi[i].F != Sl[i].F) {
                cout << "NO" << '\n';
                return;
            }
            if(Sl[i].S < Pi[i].S || Sl[i].S > 2*Pi[i].S) {
                cout << "NO" << '\n';
                return;
            }
        }
        cout << "YES" << '\n';
    }
}

int main(){
	fastIO();
	int tc = 1;
	cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
