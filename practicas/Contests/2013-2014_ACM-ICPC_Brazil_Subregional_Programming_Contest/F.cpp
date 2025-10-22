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
    int n; cin >> n;
    int sum=0;
    vector<int> a(n); 
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum+=a[i];
    }
    if(sum%3!=0){
        cout<<"0\n";
        return 0;
    }
    vector<ll> prefix(2*n+1, 0);
    for(int i=1; i<=2*n; i++){
        prefix[i]+=prefix[i-1]+a[(i-1)%n];
    }
    
    int aux=0, div=sum/3, last=0; ll ans=0;
    for (int i = 0; i < n; i++) {
        aux += (int)a[i];
        if (aux >= div) { aux -= (int)a[last]; last++; }
        auto L  = prefix.begin() + (i+1);
        auto R  = prefix.begin() + (i+n+1); 
        auto it  = lower_bound(L, R, prefix[i] + div);
        if (it == R || *it != prefix[i] + div) continue;
        auto it2 = lower_bound(it + 1, R, prefix[i] + 2LL * div);
        if (it2 != R && *it2 == prefix[i] + 2LL * div) ans++;
    }
    cout<<ans/3<<'\n';
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
