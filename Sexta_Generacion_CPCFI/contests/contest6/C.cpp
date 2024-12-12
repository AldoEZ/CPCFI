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

set<int> s;

bool is_prime(int k) {
    if(k == 0 || k == 1 || k == 4) return false;

    for (auto x : s) {
        if (k % x == 0) {
            return false;
        }
    }

	for(int x = *s.rbegin(); x < sqrt(floor(k)); x++) {
        if (k % x == 0) {
            return false;
        }
    }

    return true;
}


void solve() {
	int i, j, cont;
	cont = 0;
	cin >> i >> j;
	for(int k = i; k <= j; k++) {
        if (is_prime(k)) {
            cont++;
            s.insert(k);
        }
	}

	cout<<cont<<endl;
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
