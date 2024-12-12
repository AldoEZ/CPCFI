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
	int n, k;
	cin >> n >> k;
	vector <int> a(n);
	ll total = 1;
	int minimo = 10000000;
	int cont = 100000;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		total *= a[i];
	}
	if(total%k == 0) {
		cout << 0 << endl;
		return;
	}
	sort(a.begin(), a.end());
	for(int i = 0; i < n; i++) {
		minimo = abs(k-a[i]);
		if((a[i]+minimo)%k == 0) {
			if(minimo < cont) {
				cont = minimo;
			}
		}
	}
	cout << cont << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc = 1;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		solve();
	}
}
