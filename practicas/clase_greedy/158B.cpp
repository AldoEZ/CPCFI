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
    int a1 = 0, a2 = 0, a3 = 0, resp = 0;
    
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x == 1) a1++;
        else if(x== 2) a2++;
        else if(x == 3) a3++;
        else resp++;
    }
    
    if(a3 >= a1) { resp += a3; a1 = a3 = 0; }
    else if(a3 < a1) { resp += a3; a1 -= a3; a3 = 0; }
    
    if(a2 > 0) { resp += a2/2; a2 %= 2; }
    
    int r = a1 + (a2*2);
    
    if(r <= 4 && r > 0) resp += 1;
    else if(r%4 != 0) resp += (r/4)+1;
    else resp += (r/4);
    
    cout << resp << endl;
}

int main(){
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++)solve();
}
