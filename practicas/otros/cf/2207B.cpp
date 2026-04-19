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
    int n,m,l; cin >> n >> m >> l;
    vi flashes(n);
    for(int &i : flashes) cin >> i;
    
    int flash = 0;
    int cnt_animatronics = min(m, (n-flash+1));
    vi animatronics(cnt_animatronics,0);
    
    for(int i = 1; i <= l; i++) {
        ++*min_element(all(animatronics));
        if(flash < n && flashes[flash] == i) {
            flash++;
            animatronics.erase(animatronics.begin());
            cnt_animatronics = min(m, (n-flash+1));
            animatronics.resize(cnt_animatronics,0);
        }
        // for(int i : animatronics) cout << i << " ";
        // cout << '\n';
    }
    cout << animatronics[0] << '\n';
}

int main() {
	fastIO();
	int tc = 1;
	cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
