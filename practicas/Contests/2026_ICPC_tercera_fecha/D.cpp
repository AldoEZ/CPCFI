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

void setIO(string p){
	freopen((p + ".in").c_str(), "r", stdin);
	freopen((p + ".out").c_str(), "w", stdout);
}

bool check(vector<vector<char>> land, vector<vector<char>> laux, int n, int m) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(land[i][j] != laux[i][j]) return 0;
		}
	}
	return 1;
}

vector<vector<char>> giraDerecha(vector<vector<char>> land, int n, int m) {
	vector<vector<char>> laux(n, vector<char>(m));
	int ii = 0, jj = 0;
	for(int j = m-1; j >= 0; j--) {
		jj = 0;
		for(int i = 0; i < n; i++) {
			laux[i][j] = land[ii][jj];
			jj++;
		}
		ii++;
	}
	return laux;
}

vector<vector<char>> giraAbajo(vector<vector<char>> land, int n, int m) {
	vector<vector<char>> laux(n, vector<char>(m));
	int ii = 0, jj = 0;
	for(int i = n-1; i >= 0; i--) {
		jj = 0;
		for(int j = m-1; j >= 0; j--) {
			laux[i][j] = land[ii][jj];
			jj++;
		}
		ii++;
	}
	return laux;
}

vector<vector<char>> voltear(vector<vector<char>> land, int n, int m) {
	vector<vector<char>> laux(n, vector<char>(m));
	for(int i = 0; i < n; i++) {
		int jj = 0;
		for(int j = m-1; j >= 0; j--) {
			laux[i][j] = land[i][jj];
			jj++;
		}
	}
	return laux;
}

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<char>> land(n, vector<char>(m));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) cin >> land[i][j];
	}
	
	int arns = 1;
	vector<vector<char>> laux;
	bool ch;
	if(n == m) {
		int i = 3;
		laux = land;
		while(i--) {
			laux = giraDerecha(laux, n, m);
			ch = check(land, laux, n, m);
			if(ch) arns++;
		}
		
		laux = voltear(land, n, m);
		ch = check(land, laux, n, m);
		if(ch) arns++;
		
		i = 3;
		while(i--) {
			laux = giraDerecha(laux, n, m);
			ch = check(land, laux, n, m);
			if(ch) arns++;
		}
	} else {
		laux = giraAbajo(land, n, m);
		ch = check(land, laux, n, m);
		if(ch) arns++;
		
		laux = voltear(land, n, m);
		ch = check(land, laux, n, m);
		if(ch) arns++;
		
		laux = giraAbajo(laux, n, m);
		ch = check(land, laux, n, m);
		if(ch) arns++;
	}
	cout << arns << '\n';
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
