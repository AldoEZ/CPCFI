#include <bits/stdc++.h>

using namespace std;

void solve() {
  int k, q;
  cin >> k >> q;
  
  vector<int> ki(k);
  vector<int> qi(q);
     
  for (int i = 0; i < 1; i++) {
    cin >> ki[i];
  }
  
  for (int i = 0; i < q; i++) {
    cin >> qi[i];
  }
   
  for (int i = 0; i < q; i++) {
    if (qi[i] < ki[0]) cout << qi[i] << " ";
    else cout << (ki[0]-1) << " ";
   }
    cout << endl;
}

int main() {
  int t = 0;
  cin >> t;
  for(int i = 0; i < t; i++) {
    solve();
  }
}
