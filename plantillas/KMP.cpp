#include <bits/stdc++.h>

using namespace std;

#define fastIO() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()	
#define pb push_back				
#define sz(a) int(a.size())				
#define F first
#define S second
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pair<int,int>> vpii;
typedef vector<pair<ll,ll>> vpll;
const int MOD = 1e9+7;
const int INF = INT_MAX;	
const ll INF64 = LLONG_MAX;		
const long double EPS = 1e-9;			
const long double PI = acosl(-1.0L);

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

int main(){
	fastIO();
	vi kmp = KMP();
    int n = sz(kmp);
    for(int i = 0; i < n; i++) cout << kmp[i] << " ";
    cout << '\n';
}
