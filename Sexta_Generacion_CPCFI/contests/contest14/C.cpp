#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),vrend()
#define pb push_back 
#define INF 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int MAX = 200'007;
const int MOD = 1'000'000'007;

void solve() {
    ll n, s, m;
    cin >> n >> s >> m;
    vector<pair<ll,ll>> ni(n); 
    for(int i = 0; i < n; i++) {
        cin >> ni[i].first >> ni[i].second; 
    }
    ll max = ni[0].first;
    for(int i = 0; i < n-1; i++) {
        ll aux = ni[i+1].first - ni[i].second;
        if(aux > max) max = aux;
    }
    if(m-ni[n-1].second > max) max = m-ni[n-1].second;
    
    if(max >= s) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc = 1;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		solve();
	}
}
