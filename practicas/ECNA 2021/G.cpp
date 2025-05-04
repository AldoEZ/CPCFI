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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pair<int,int>> vpii;
typedef vector<pair<ll,ll>> vpll;
const int MOD = 1e9+7;
const int INF = INT_MAX;	
const ll INF64 = LLONG_MAX;		
const long double EPS = 1e-9;			
const long double PI = acosl(-1.0L);

bool correctOp(string X,string Y,string Z, char op) {
    ll x = stoll(X), y = stoll(Y), z = stoll(Z);
    if(op == '+') return x+y == z;
    else if(op == '*') return x*y == z;
    return 0;
}

void solve(){
    string x,y,z,op,igual;
    cin >> x >> op >> y >> igual >> z;
    
    for(int i = 1; i < sz(x); i++) 
        for(int j = 1; j < sz(y); j++) {
            string preX = x.substr(0,i);
            string preY = y.substr(0,j);
            
            string newX = preY + x.substr(sz(preX));
            string newY = preX + y.substr(sz(preY));
            
            if(sz(newX) > 1 && newX[0] == '0' || sz(newY) > 1 && newY[0] == '0') continue;
            
            if(correctOp(newX,newY,z, op[0])) {
                cout << newX << " " << op << " " << newY << " = " << z << '\n';
                return;
            }
        }
    
    for(int i = 1; i < sz(x); i++) 
        for(int j = 1; j < sz(z); j++) {
            string preX = x.substr(0,i);
            string preZ = z.substr(0,j);
            
            string newX = preZ + x.substr(sz(preX));
            string newZ = preX + z.substr(sz(preZ));
            
            if(sz(newX) > 1 && newX[0] == '0' || sz(newZ) > 1 && newZ[0] == '0') continue;
            
            if(correctOp(newX,y,newZ, op[0])) {
                cout << newX << " " << op << " " << y << " = " << newZ << '\n';
                return;
            }
        }
    
    for(int i = 1; i < sz(y); i++) 
        for(int j = 1; j < sz(z); j++) {
            string preY = y.substr(0,i);
            string preZ = z.substr(0,j);
            
            string newY = preZ + y.substr(sz(preY));
            string newZ = preY + z.substr(sz(preZ));
            
            if(sz(newY) > 1 && newY[0] == '0' || sz(newZ) > 1 && newZ[0] == '0') continue;
            
            if(correctOp(x,newY,newZ, op[0])) {
                cout << x << " " << op << " " << newY << " = " << newZ << '\n';
                return;
            }
        }
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
