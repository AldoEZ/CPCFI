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
    int n;cin >> n;
    int l=0;
    for (int i = 0; i < 32; i++) {
        if(n&(1<<i))l=i;
    }
    cout << l << endl;
    
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) {
		solve();
	}
}
