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

void solve() {
    int n; cin >> n;
    int cntEve = 0, cntAle = 0;
    while(n--) {
        string g1, g2; cin >> g1 >> g2;
        if(g1 == "Piedra" && g2 == "Tijeras") cntEve++;
        else if(g1 == "Tijeras" && g2 == "Papel") cntEve++;
        else if(g1 == "Papel" && g2 == "Piedra") cntEve++;
        
        else if(g2 == "Tijeras" && g1 == "Papel") cntAle++;
        else if(g2 == "Papel" && g1 == "Piedra") cntAle++;
        else if(g2 == "Piedra" && g1 == "Tijeras") cntAle++;
    }
    
    if(cntEve > cntAle) cout << "Eve" << '\n';
    else if(cntEve < cntAle) cout << "Ale" << '\n';
    else cout << "Empate" << '\n';
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
