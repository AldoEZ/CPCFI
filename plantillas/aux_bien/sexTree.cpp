#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// we store the Segment Tree simply as an array  t[]  with a size of four times the input size n :
int n;
vector<int> t;

// The procedure for constructing the Segment Tree from a given array a[] looks like this: 
// it is a recursive function with the parameters  a[] (the input array),  v  (the index of
//  the current vertex), and the boundaries  tl  and  tr  of the current segment. In the 
// main program this function will be called with the parameters of the root vertex:  v = 1,  
// tl = 0 , and  tr = n - 1.

// el nodo raíz está en v = 1
// su hijo izquierdo en 2*v
// su hijo derecho en 2*v + 1
// Eso es exactamente igual a cómo se representa un heap en un arreglo.

// [tl, tr] → Segmento del arreglo original que representa el nodo actual del segment tree.
// Ejemplo: El nodo 1 del segment tree, representa el arreglo original completo

// [l, r] → Segmento del arreglo original que tú quieres consultar.

ll merge(ll a, ll b) {
    return min(a, b);
}


void build(vi &a, int v, int tl, int tr)
{
  if (tl == tr)
  {
    t[v] = a[tl];
    return;
  }
  int tm = tl + (tr - tl) / 2;
  build(a, v * 2, tl, tm);
  build(a, v * 2 + 1, tm + 1, tr);
  t[v] = merge(t[2 * v], t[2 * v + 1]);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}



ll query(int v, int tl, int tr, int l, int r)
{

  if (tl >= l && tr <= r)
  {
    return t[v];
  }
  if (tl > r || tr < l)
  {
    return INT_MAX;
  }
  int tm = tl + (tr - tl) / 2;
  return merge(query(v * 2, tl, tm, l, r), query(v * 2 + 1, tm + 1, tr, l, r));
}

void solve()
{
  int n, q;
  cin >> n >> q;
  nums.assign(n, 0);
  t.assign(4*n, INT_MIN);

  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  st.assign(n * 4, neuter);
  build(1, 0, n - 1);

  while (q--)
  {
    int op;
    cin >> op;

    if (op == 1)
    {
      int k;
      ll u;
      cin >> k >> u;
      update(1, 0, n - 1, k - 1, u);
    }
    else
    {
      int a, b;
      cin >> a >> b;
      cout << query(1, 0, n - 1, a - 1, b - 1) << endl;
    }
  }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
  int tt = 1;
  while (tt--)
  {
    solve();
  }

  return 0;
}