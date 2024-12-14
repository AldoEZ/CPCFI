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
    int n; cin >> n;
    vll r(n);
    ll sumR = 0, maxR = 0;
    for(int i = 0; i < n; i++) {
        cin >> r[i];
        sumR += r[i];
        maxR = max(sumR, maxR);
    }
    
    int m; cin >> m;
    vll b(m);
    ll sumB = 0, maxB = 0;
    for(int j = 0; j < m; j++) {
        cin >> b[j];
        sumB += b[j];
        maxB = max(sumB, maxB);
    }
    
    cout << maxR + maxB << endl;
}

int main(){
	fastIO();
	int tc = 1;
	cin >> tc;
	for (int t = 1; t <= tc; t++)solve();
}
