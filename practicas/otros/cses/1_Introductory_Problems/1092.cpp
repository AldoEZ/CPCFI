// cses
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
    ll n; cin >> n;
    
    ll sum = 0, tam = 0;
    vector<pair<ll,bool>> nums;
    for(ll i = 1; i <= n; i++) { sum += i; nums.pb({i,1}); }
    
    if(sum%2 != 0) cout << "NO\n";
    else {
        cout << "YES\n";
        
        ll ref = sum/2;
        vll part1;
        while(sum > ref) {
            if(sum-n < ref) {
                ll e = sum - ref;
                part1.pb(e);
                nums[e-1].S = 0;
                sum -= e;
            } else {
                part1.pb(n);
                sum -= n;
                nums[n-1].S = 0;
                n--;
            }
        }
        cout << sz(part1) << '\n';
        for(int i = sz(part1)-1; i >= 0; i--) cout << part1[i] << " ";
        
        for(auto i : nums) 
            if(i.S) tam++;
        cout << '\n' << tam << '\n';
        for(auto i : nums) 
            if(i.S) cout << i.F << " ";
        cout << '\n';
    }
}


int main(){
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
