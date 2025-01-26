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

void solve(){
    int n, k; cin >> n >> k;
    
    vector<pair<vi,int>> scs;
    
    for(int i = 0; i < n; i++) {
        vi aux(k);
        for(int j = 0; j < k; j++) {
            cin >> aux[j];
        }
        scs.pb({aux,i+1});
    }
    
    sort(all(scs));
    
    for(int i=0;i<n-1;i++){
		for(int j = 0;j<k;j++){
			if(scs[i].S[j] > scs[i+1].S[j]){
				cout << "NO\n";
				return;
			}
		}
	}
    
    cout << "YES" << endl;
    for(int i = 0; i < n; i++) {
        cout << scs[i].S << " ";
    }
    cout << "\n";
}

int main(){
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++)solve();
}
