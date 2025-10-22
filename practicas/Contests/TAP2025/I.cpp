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
    int N,M; cin >> N >> M;
    
    ll sumInes = 0;
    vll sumPlayers(N,0);
    
    for(int i = 0; i < M; i++) {
        int op1, op2; cin >> op1 >> op2;
        vi players(N);
        for(auto &i : players) cin >> i;
        
        int cg1 = 0;
        for(auto i : players) {
            if(i == 1) cg1++;
        }
        
        if(floor(op1/(cg1+1)) >= op2) {
            cg1++;
            sumInes += floor(op1/cg1);
        } else sumInes += op2;
        
        for(int i = 0; i < sz(players); i++) {
            if(players[i] == 1) sumPlayers[i] += floor(op1/cg1);
            else sumPlayers[i] += op2;
        }
    }
    for(auto i : sumPlayers) cout << i << " ";
    cout << sumInes << '\n';
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
