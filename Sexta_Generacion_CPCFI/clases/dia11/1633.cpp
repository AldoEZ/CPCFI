#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define TAM 1000000
#define MOD 1000000007

int main() {
    vector<ll> dp(TAM,0);
    ll n = 1;
    cin >> n;
    dp[0]=1;dp[1]=1;dp[2]=2;dp[3]=4;dp[4]=8;dp[5]=16;dp[6]=32;
    
    for(ll i = 7; i <= n; i++) {
        for(int j = 1; j <= 6; j++) {
            dp[i] += dp[i-j];
            dp[i] %= MOD;
        }
    }
    
    cout << dp[n] << endl;
}
