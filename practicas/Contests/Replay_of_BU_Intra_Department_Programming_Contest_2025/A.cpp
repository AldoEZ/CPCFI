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

struct Node{
	ll n = 0;
	Node operator+(Node b){return {(n+b.n)%MOD};}
};

class Fenwick_Tree{
public:
	vector<Node> tree;
	int n;
	Fenwick_Tree(int x){
		n = x+1;tree.resize(n);
	}
    
	ll sum(int r){
		r++;
		Node ans = {0};
		while(r){
			ans = ans + tree[r];
			r -= r&-r;
		}
		return ans.n;
	}
    
	void update(int id, Node val){
		id++;
		while(id < n){
			tree[id]  = tree[id]+val;
			id += id&-id;
		}
	}
};

void solve(){
	int n; cin >> n;
	vll a(n);
	for(ll &i : a) cin >> i;
    
	vll b = a;
	map<ll,int> mp;
	sort(rall(b));
	b.erase(unique(all(b)),b.end());
    
	int cnt = 1;
	for(ll i:b)mp[i] = cnt++;
    
	Fenwick_Tree fw1(sz(mp)+1),fw2(sz(mp)+1);
    
	auto binpow = [](ll a)->ll{
		ll ans = 1;
		a%=MOD;
		ll b =MOD-2;
		while(b){
			if(b&1)(ans*=a)%=MOD;
			(a*=a)%=MOD;
			b>>=1;
		}
		return ans;
	};
	for(ll i:a){
		fw1.update(mp[i],{i});
		fw2.update(mp[i],{1});
		ll total = fw2.sum(mp[i]);
		ll sum = fw1.sum(mp[i]);
        
		cout << sum*binpow(total)%MOD << ' ';
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++)solve();
}
