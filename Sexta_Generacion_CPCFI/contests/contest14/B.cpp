#include <bits/stdc++.h>

using namespace std;

#define fastIO() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define rall(v) v.rbegin(),v.rend()
typedef long long ll;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll suma = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        suma += a[i];
    }
    
    sort(rall(a));
    ll A = 0;
    ll B = 0;
    
    for(int i = 0; i < n; i++) {
        if(i%2 == 0) {
            A += a[i];
        } else {
            ll diferencia = min(k, a[i-1] - a[i]);
            a[i] += diferencia;
            k -= diferencia;
            B += a[i];
        }
    }
    cout << A-B << endl;
}

int main() {
	fastIO();
	int tc = 1;
	cin >> tc;
	for (int t = 0; t < tc; t++) solve();
}
