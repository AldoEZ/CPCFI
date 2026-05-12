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

void solve() {
    int n; cin >> n;
    cin.ignore();
    
    for(int i = 0; i < n; i++) {
        string s; getline(cin, s);
        int aux = 0, l = sz(s);
        string finalS = "";
        while(aux < l) {
            if(isdigit(s[aux])) {
                int j = 1, k = aux+1;
                while(k < l && isdigit(s[k])) {
                    j++; k++;
                }
                string num = s.substr(aux,j);
                int nnum = sz(num)-1,sznum = sz(num)-1, cntZeros = 0;
                while(nnum >= 0 && num[nnum] == '0') { 
                    cntZeros++;
                    nnum--;
                }
                
                if(!cntZeros || (aux > 0 && s[aux-1] != ' ') || (k != l && s[k] != ' ')) {
                    finalS += num;
                } else if(cntZeros == sznum && num[0] == '1' && cntZeros >= 4) {
                    string num1 = "10^{" + to_string(cntZeros) + '}';
                    finalS += num1;
                } else if(cntZeros >= 4) {
                    if(cntZeros == sznum) {
                        string num2 = num.substr(0,1) + "\\cdot10^{" + to_string(cntZeros) + '}';
                        finalS += num2;
                    } else {
                        int tam = sz(num)-cntZeros-1;
                        string num3 = num.substr(0,1) + '.' + num.substr(1,tam) + "\\cdot10^{" + to_string(cntZeros+tam) + '}';
                        finalS += num3;
                    }
                } else finalS += num;
                
                aux = k;
            } else { finalS += s[aux]; aux++; }
        }
        cout << finalS << '\n';
    }
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
