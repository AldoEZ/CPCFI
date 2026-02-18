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
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
const int MOD = 1e9+7;
const int INF = INT_MAX;	
const ll INF64 = LLONG_MAX;		
const long double EPS = 1e-9;			
const long double PI = acosl(-1.0L);

void solve() {
    vector<int> l1(3), l2(3);
    cin >>  l1[0]>> l1[1] >> l1[2];
    cin >> l2[0] >> l2[1] >> l2[2];
    vector<int> ans(9);
    int cnt=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            ans[cnt]=l1[i]/l2[j%3];
            cnt++;
        }
    }
    
    int answer=0;
    for(int i=0; i<3; i++){
        for(int j=3; j<6; j++){
            for(int k=6; k<9; k++){
                if(i+3!=j && j+3!=k && i+6!=k){
                    answer=max(answer, ans[i]*ans[j]*ans[k]);
                }
            }
        }
    }
    cout<<answer<<'\n';
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
