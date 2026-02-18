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

bool es_primo(int n) {
    if(n == 1) return false;
    if(n == 2) return true;
    if(n%2 == 0) return false;
    for(int i = 3; i*i <= n; i+=2) {
        if(n%i == 0) return false;
    }
    return true;
}

void solve() {
    int n,m; cin >> n >> m;
    vi nums(n);
    for(auto &i : nums) cin >> i;
    
    int cnt = 0;
    vi sobrantes;
    for(int i = 0; i < n; i++) {
        if(es_primo(nums[i])) cnt++;
        else if(es_primo(nums[i]+1) && m>0) { m--; cnt++; }
        else if(es_primo(nums[i]-1) && m>0) { m--; cnt++; }
        else sobrantes.pb(nums[i]);
    }
    vi ocupa;
    if(sz(sobrantes) > 0 && m > 0) {
        for(auto num : sobrantes) {
            int pmenor=1,pmayor=1;
            for(int i = 1; i <= m; i++) {
                if(es_primo(sobrantes[i]+i)) break;
                pmayor++;
            }
            for(int i = 1; i <= m; i++) {
                if(es_primo(sobrantes[i]-i)) break;
                pmenor++;
            }
            ocupa.pb(min(pmenor,pmayor));
        }
        sort(all(ocupa));
        for(int i = 0; i < sz(ocupa); i++) {
            if(m-ocupa[i] < 0) break;
            cnt++;
            m-=ocupa[i];
        }
    }
    cout << cnt << '\n';
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
