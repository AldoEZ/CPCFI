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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int MOD = 1e9+7;
const int INF = INT_MAX;	
const ll INF64 = LLONG_MAX;		
const long double EPS = 1e-9;			
const long double PI = acosl(-1.0L);

void solve(){
    int q; cin >> q;
    bool flag = false;
    vector<pair<string,string>> users;
    
    for(int i = 0; i < q; i++) {
        string s1, s2; cin >> s1 >> s2;
        flag = false;
        for(auto &a : users) {
            if(a.S == s1) {
                a.S = s2;
                flag = true;
            }
        }
        if(!flag) {
            pair<string,string> u1;
            u1.F = s1;
            u1.S = s2;
            users.pb(u1);
        }
    }
    cout << sz(users) << endl;
    for(auto &a : users) {
        cout << a.F << " " << a.S << endl;
    }
}

int main(){
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++)solve();
}
