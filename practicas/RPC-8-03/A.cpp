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

struct Node{
	ll val = INF;
	int pos = 0;
    
	Node operator+(Node b){
		if(val == b.val){
			if(pos > b.pos)return b;
			else return {val,pos};
		}
		if(val < b.val)return{val,pos};
		else return b;
	}
};

class Segment_Tree{
	public:
	int n,k=0;
	vector<Node> tree;
    
	Segment_Tree(int x = 1e5+10){
		n = x;
		while((1<<k)<n)k++;
		tree.resize(2*(1<<k)+1);
	}
    
	void build(vector<pii> &arr){
		for(int i=0;i<n;i++)tree[(1<<k)+i] = {arr[i].F , arr[i].S};
		for(int i = (1<<k)-1; i>0;i--)tree[i] = tree[i*2]+tree[i*2+1];
	}
    
	void update(int a, ll b){
		a+= (1<<k);
		tree[a] = {tree[a].val+b,tree[a].pos};
		for(a/=2;a>=1;a/=2)tree[a] = tree[a*2]+tree[a*2+1];
	}
    
	int query(int a,int b){
		a += (1<<k);
		b += (1<<k);
		Node s;
		while(a<=b){
			if(a%2 == 1)s = s+ tree[a++];
			if(b%2 == 0)s = s+ tree[b--];
			a/=2;
			b/=2;
		}
		return s.pos;
	}
};

void solve() {
	int t, p, fav; cin >> t >> p >> fav;
	
    Segment_Tree sg;
}

int main(){
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++)solve();
}
