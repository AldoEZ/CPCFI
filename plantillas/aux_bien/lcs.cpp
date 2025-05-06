// longest common subsequence
#include <bits/stdc++.h>

using namespace std;
			
#define sz(a) int(a.size())
typedef long long ll;
typedef vector<ll> vll;

string s1 = "AGGTAB", s2 = "GXTXAYB";
ll m = sz(s1), n = sz(s2);
vector<vll> memo(m+1, vll(n+1,-1));

ll lcs(string& s1, string& s2, ll m, ll n, vector<vll>& memo) {
    if(m == 0 || n == 0) return 0;
    
    if(memo[m][n] != -1) return memo[m][n];
    
    if(s1[m-1] == s2[n-1]) return memo[m][n] = 1 + lcs(s1,s2,m-1,n-1,memo);
    
    return memo[m][n] = max(lcs(s1,s2,m,n-1,memo), lcs(s1,s2,m-1,n,memo));
}
