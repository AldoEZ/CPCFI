#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = 1e9+7;

ll binPow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b&1) (ans *= a) %= MOD;
        (a *= a) %= MOD;
        b >>= 1;
    }
    return ans;
}
