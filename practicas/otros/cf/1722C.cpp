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
const int MOD = 1e9+7;
const int INF = INT_MAX;	
const ll INF64 = LLONG_MAX;		
const long double EPS = 1e-9;			
const long double PI = acosl(-1.0L);

void solve(){
    int n; cin >> n;
    vs p1(n); vs p2(n); vs p3(n);
    map<string, int> pi;
    
    for(int i = 0; i < n; i++) {
        cin >> p1[i];
        pi[p1[i]] = 3;
    }
    for(int j = 0; j < n; j++) {
        cin >> p2[j];
        
        if(pi.find(p2[j]) != pi.end()) pi[p2[j]] -= 2;
        else pi[p2[j]] = 3;
    }
    for(int k = 0; k < n; k++) {
        cin >> p3[k];
        if(pi.find(p3[k]) != pi.end()) {
            if(pi[p3[k]] == 1) pi[p3[k]] = 0;
            else pi[p3[k]] -= 2;
        } else {
            pi[p3[k]] = 3;
        }
    }
    
    int p1p = 0, p2p = 0, p3p = 0;
    
    for(int i = 0; i < n; i++) p1p += pi[p1[i]];
    for(int j = 0; j < n; j++) p2p += pi[p2[j]];
    for(int k = 0; k < n; k++) p3p += pi[p3[k]];
    
    cout << p1p << " " << p2p << " " << p3p << endl;
}

int main(){
	fastIO();
	int tc = 1;
	cin >> tc;
	for (int t = 1; t <= tc; t++)solve();
}
