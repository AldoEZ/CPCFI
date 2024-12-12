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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int MOD = 1e9+7;
const int INF = INT_MAX;	
const ll INF64 = LLONG_MAX;		
const long double EPS = 1e-9;			
const long double PI = acosl(-1.0L);

void solve(){
    int k, r; cin >> k >> r;
    int resp = 0;
    int i = 1;
    
    if(k%10 == 0 || k%10-r == 0){
        cout << 1 << endl;
        return;
    }
    int kaux = k;
    while(i < 15) {
        int aux = kaux%10;
        
        if(aux - r  == 0 || aux == 0) {
            break;
        } else {
            resp++;
            kaux = k * i;
            i++;
        }
    }
    
    cout << resp << endl;
}

int main(){
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++)solve();
}
