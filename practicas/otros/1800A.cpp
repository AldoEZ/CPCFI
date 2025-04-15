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
    int n; cin >> n;
    string s; cin >> s;
    
    // m
    int i = 0;
    if(s[i] != 'M' && s[i] != 'm') { cout << "NO" << '\n'; return; }
    while(s[i] == 'M' || s[i] == 'm') i++;
    
    if(s[i] != 'E' && s[i] != 'e') { cout << "NO" << '\n'; return; }
    while(s[i] == 'E' || s[i] == 'e') i++;
    
    if(s[i] != 'O' && s[i] != 'o') { cout << "NO" << '\n'; return; }
    while(s[i] == 'O' || s[i] == 'o') i++;
    
    if(s[i] != 'W' && s[i] != 'w') { cout << "NO" << '\n'; return; }
    while(s[i] == 'W' || s[i] == 'w') i++;
    
    if(i < n) cout << "NO" << '\n';
    else cout << "YES" << '\n';
}

int main(){
	fastIO();
	int tc = 1;
	cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
