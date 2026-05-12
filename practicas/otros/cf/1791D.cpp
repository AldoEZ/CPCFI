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
typedef vector<bool> vb;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
const int MOD = 1e9+7;
const int INF = INT_MAX;	
const ll INF64 = LLONG_MAX;		
const long double EPS = 1e-9;			
const long double PI = acosl(-1.0L);

void setIO(string p){
	freopen((p + ".in").c_str(), "r", stdin);
	freopen((p + ".out").c_str(), "w", stdout);
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    
    vi pre(n), suf(n), ap(26,0);
    int diferentes = 0;
    for(int i = 0; i < n; i++) {
        int aux = s[i] - 'a';
        if(ap[aux] == 0) diferentes++;
        
        ap[aux]++;
        pre[i] = diferentes;
    }
    
    fill(all(ap), 0);
    diferentes = 0;
    for(int i = n-1; i >= 0; i--) {
        int aux = s[i] - 'a';
        if(ap[aux] == 0) diferentes++;
        
        ap[aux]++;
        suf[i] = diferentes;
    }
    
    int arns = 0;
    for(int i = 0; i < n-1; i++) {
        arns = max(arns, pre[i]+suf[i+1]);
    }
    cout << arns << '\n';
}

int main() {
	fastIO();
	int tc = 1;
	cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
