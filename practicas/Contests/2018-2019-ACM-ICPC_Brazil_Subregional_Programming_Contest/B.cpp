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

vector<vi> grundy(101,vi (101,0));

int mex(int x,int y){
	vector<bool> seen(1000,0);
	for(int i = 0;i<x;i++)
		seen[grundy[i][y]] = 1;
    
	for(int i = 0;i<y;i++)
		seen[grundy[x][i]] = 1;
    
	for(int i=1;i<=min(x,y);i++)
		seen[grundy[x-i][y-i]] = 1;
    
	for(int i=0;i<1000;i++)
		if(!seen[i])return i;
}

void solve(){
	int n;cin >> n;
	
	for(int i=0;i<=100;i++){
		grundy[i][0] = grundy[0][i] = grundy[i][i] = 999;
	}
	for(int i=1;i<=100;i++)
		for(int j=1;j<=100;j++)
			if(i!=j)grundy[i][j] = mex(i,j);
    
	int ans = 0;
	while(n--){
		int a,b;
		cin >> a >> b;
		if(grundy[a][b] == 999){
			cout << "Y\n";
			return;
		}
		ans ^= grundy[a][b];
	}
    
	cout << (ans != 0?"Y":"N") << '\n';
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++)solve();
}
