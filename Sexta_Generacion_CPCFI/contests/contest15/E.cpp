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

int cont = 0;

void dfs(vector<vector<int>> &graph, set<int> &visitados, int nodo){
    //Importante recibir el grafo y el set de visitados por referencia
    //cout<<nodo<< endl; //Acci�n ejemplo a realizar para cada nodo recorrido
    visitados.insert(nodo);
    
    for(int i=0; i<graph[nodo].size(); i++){
        //Recorrer nodos adyacentes
        if(visitados.find(graph[nodo][i])==visitados.end())
            dfs(graph,visitados,graph[nodo][i]);
    }
    cont++;
}

void solve(){
    int vertices,aristas;
    cin>>vertices>>aristas;
    
    vector<vector<int>> graph(vertices+1); 
    //El más uno es para no tener problemas con array indexing, el índice 0 no suele usarse.
    for(int i=0; i<aristas; i++){
        int uno,dos;
        cin>>uno>>dos;
        graph[dos].push_back(uno);
        //graph[uno].push_back(dos); 
    }
    
    int aux;
    queue<int> q;
    set<int> visitados; 
    
    dfs(graph,visitados,1);
    if(cont > 1) {
        cout << cont-1 << endl; 
    }
    else cout << cont << endl; 
}

int main() {
	fastIO();
	int tc = 1;
	//cin >> tc;
	for (int t = 1; t <= tc; t++)solve();
}
