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

void solve() {
    ll n; cin >> n;
    
    ll sum = 0;
    vll nums;
    for(ll i = 1; i <= n; i++) { sum += i; nums.pb(i); }
    
    if(sum%2 != 0) cout << "NO\n";
    else {
        cout << "YES" << '\n';
        vll p1, p2;
        if(n%2 == 0) {
            for(int i = 0; i < (n/2); i++) {
                if(i%2 == 0) { p1.pb(nums[i]);p1.pb(nums[n-i-1]); }
                else { p2.pb(nums[i]);p2.pb(nums[n-i-1]); }
            }
        } else {
            for(int i = 0; i < (n/2); i++) {
                if(i%2 == 0) { p1.pb(nums[i]);p1.pb(nums[n-i-2]); }
                else { p2.pb(nums[i]);p2.pb(nums[n-i-2]); }
            }
            p2.pb(nums[n-1]);
        }
        cout << sz(p1) << '\n';
        for(auto i : p1) cout << i << " ";
        cout << '\n' << sz(p2) << '\n';
        for(auto i : p2) cout << i << " ";
    }
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
