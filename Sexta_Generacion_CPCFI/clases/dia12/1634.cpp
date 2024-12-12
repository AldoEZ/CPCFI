// cses
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
typedef long long ll;

int main() {
    int n, x = 0;
    cin >> n >> x;
    vector<ll> ci(n);
    for(int i = 0; i < n; i++) {
        cin >> ci[i];
    }
    
    vector<ll> dp(x+1, INF);
    dp[0] = 0;
    
    for(int i = 1; i <= x; i++) {
        for(int j = 0; j < n; j++) {
            if(ci[j] > i || dp[i - ci[j]] == INF) continue;
            dp[i] = min(dp[i], dp[i - ci[j]] + 1);
        }
    }
    
    if(dp[x] != INF) cout << dp[x] << endl;
    else cout << -1 << endl;
}