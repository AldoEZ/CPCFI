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
    int n; 
    cin >> n; 
 
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        cin >> a[i].second;
    }
 
    int l = 0, r = 1e9;
    bool flag = 0;
    int ans = 1e9;
 
    while(r >= l){
        int mid = (l + r) / 2;
        flag = 0;
 
        for(int i = 0; i <= mid; i++){
            int x = mid - i, y = i;
 
            if(x == 0) { 
                flag = 1;
                continue;
            }
 
            bool ok = 1;
            for(int j = 0; j < n; j++){
                int aux = (a[j].second + x - 1) / x;
                if((aux - 1) * a[j].first >= y){
                    ok = 0;
                    break;
                }
            }
 
            if(ok){
                flag = 0;
                break;
            } else {
                flag = 1;
            }
        }
        if(!flag){
            ans = min(ans, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    
    cout << ans << '\n';
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
