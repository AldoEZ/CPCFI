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

void crearSufix(vi& arr, vi& sufix, int n) {
    sufix[n-1] = arr[n-1];
    
    for(int i = n-2; i >= 0; i--) {
        sufix[i] = sufix[i+1] + arr[i];
    }
}

int main() {    
	vi arr;
    
    arr.push_back(5); arr.push_back(12);
    arr.push_back(7); arr.push_back(14);
    arr.push_back(21); arr.push_back(54);
    
    int n = size(arr);
    
    vi sufix(n);
    crearSufix(arr, sufix, n);
    
    // cout << "Arreglo Original: ";
    // for(auto i : arr) cout << i << " ";
    
    // cout << "\n    Sufix Sum:   ";
    // for(auto i : sufix) cout << i << " ";
    
    // cout << "\n";
    
    // se requiere saber la suma entre el elemento 3 y el 5
cout << sufix[2] - sufix[5] << endl;
}