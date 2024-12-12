// cses
#include <bits/stdc++.h>

using namespace std;

#define fastIO() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back 
#define INF 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int MAX = 200'007;
const int MOD = 1'000'000'007;

void addVertex(vector<vi>& grafo) {
    vi aux;
    grafo.pb(aux);
}

void addRoad(vector<vi>& grafo, int vertex1, int vertex2) {
    grafo[vertex1].pb(vertex2);
    grafo[vertex2].pb(vertex1);
}

int main() {
	fastIO();
	vector<vi> grafo;
    addVertex(grafo);
    addVertex(grafo);
    addVertex(grafo);
    addVertex(grafo);
    
    addRoad(grafo,0,1);
    addRoad(grafo,2,3);
    for(int i = 0; i < 4; i++) {
        cout << i+1 << " ";
    }
}
