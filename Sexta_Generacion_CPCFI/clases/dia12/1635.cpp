// cses
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1'000'000'007;

int main() {
    int n, x = 0;
    cin >> n >> x;
    vector<ll> ci(n);
    for(int i = 0; i < n; i++) {
        cin >> ci[i];
    }
    
    vector<ll> dp(x+1, 0);
    dp[0] = 1;
    
    for(int i = 1; i <= x; i++) {
        for(int j = 0; j < n; j++) {
            if(ci[j] > i || dp[i - ci[j]] == 0) continue;
            dp[i] += dp[i - ci[j]];
        }
        dp[i] %= MOD;
    }
    
    if(dp[x] >= 0) {
        cout << dp[x] << endl;
    }
    else cout << -1 << endl;
}
