#include <bits/stdc++.h>

using namespace std;

#define pb push_back				
#define sz(a) int(a.size())
typedef vector<int> vi;

vi LPS(string sb, int m) {
    vi lps(m,0);
    
    int i = 1, j = 0;
    while(i < m) {
        if(sb[i] == sb[j]) {
            j += 1;
            lps[i] = j;
            i += 1;
        } else {
            if(j != 0) {
                j = lps[j-1];
            } else {
                lps[i] = 0;
                i += 1;
            }
        }
    }
    return lps;
}

vi KMP() {
    string s; cin >> s;
    string sb; cin >> sb;
    
    int n = sz(s), m  = sz(sb);
    vi lps = LPS(sb,m);
    int i = 0, j = 0;
    vi ans;
    
    while(i < n) {
        if(sb[j] == s[i]) {
            j += 1;
            i += 1;
        }
        if(j == m) {
            ans.pb(i-j);
            j = lps[j-1];
        } else if(i < n && sb[j] != s[i]) {
            if(j != 0) j = lps[j-1];
            else i += 1;
        }
    }
    return ans;
}
