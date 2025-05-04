#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

vll pa, tam;
ll tco, mc;

ll get(ll a) {
    return ((pa[a] == a)? a : pa[a] = get(pa[a]));
}

void unite(ll a, ll b) {
    a = get(a);
    b = get(b);
    
    if(a == b) return;
    if(tam[a] > tam[b]) swap(a,b);
    
    tco--;
    pa[a] = b;
    tam[b] += tam[a];
    
    if(tam[b] > mc) mc = tam[b];
    return;
}