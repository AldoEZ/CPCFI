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
    string s; cin >> s;
    
    int subS = 0, n = sz(s), i =0;
    bool AB = true, BA = true;
    
    while(i < n-1) {
        if(s[i] == 'A' && s[i+1] == 'B') { 
            for(int j = i+2; j < n-1; j++) {
                if(s[j] == 'B' && s[j+1] == 'A') { cout << "YES" << endl; return; }
            } break;
        }
        i++;
    } i=0;
    
    while(i < n-1) {
        if(s[i] == 'B' && s[i+1] == 'A') { 
            for(int j = i+2; j < n-1; j++) {
                if(s[j] == 'A' && s[j+1] == 'B') { cout << "YES" << endl; return; }
            } break;
        }
        i++;
    }
    
    cout << "NO" << endl;
}

int main(){
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++)solve();
}
