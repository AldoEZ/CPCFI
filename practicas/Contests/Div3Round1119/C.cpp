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
    int n;
    cin >> n;

    vi a(n);
    for (int &x : a) cin >> x;

    int bestL = -1, bestR = -1;
    int lastOne = -1;
    int firstNonZero = -1;
    int lastNonZero = -1;

    for (int i = 0; i < n; i++) {

        if (a[i] == 1) {
            // Podemos usar el 1 anterior o los -1 anteriores
            if (firstNonZero != -1) {
                if (i - firstNonZero > bestR - bestL) {
                    bestL = firstNonZero;
                    bestR = i;
                }
            }

            // Este 1 empieza un nuevo bloque
            lastOne = i;
            firstNonZero = i;
            lastNonZero = i;
        }

        else if (a[i] == -1) {
            if (firstNonZero == -1)
                firstNonZero = i;

            lastNonZero = i;
        }
    }

    // Revisar el último bloque
    if (firstNonZero != -1 && lastNonZero != firstNonZero) {
        if (lastNonZero - firstNonZero > bestR - bestL) {
            bestL = firstNonZero;
            bestR = lastNonZero;
        }
    }

    // Construimos la respuesta
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
            if (i == bestL || i == bestR)
                cout << 1;
            else
                cout << 0;
        }
        else {
            cout << a[i];
        }

        cout << ' ';
    }

    cout << '\n';
}

int main() {
	fastIO();
	int tc = 1;
	cin >> tc;
	for (int t = 1; t <= tc; t++) solve();
}
