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
    string s; ll k; cin >> s >> k;
    
    string resp; int n = sz(s);
    
    for(size_t i = 0; i < n; i++) {
        if(isdigit(s[i])) {
            ll cont = 0;
            while(i < n && isdigit(s[i])) {
                cont = cont*10 + (s[i] - '0');
                if(cont > 1e6) {
                    cout << "unfeasible" << endl;
                    return;
                }
                i++;
            }
            if(i < n) resp.append(cont, s[i]);
        } else {
            resp.pb(s[i]);
        }
    }
    if(sz(resp) > k) {
        cout << "unfeasible" << endl;
    } else {
        cout << resp << endl;
    }
}

int main(){
	fastIO();
	int tc = 1;
	cin >> tc;
	for (int t = 1; t <= tc; t++)solve();
}
