#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<string, int>> m(n);
  int greater;
  string key;
  int value;
  for (int i = 0; i < n; i++) {
    cin >> key >> value;
    int indx = 0;
    for(int j = 0; j < i; j++) {
        if(m[j].first == key) m[j].second += value;
        if(m[j].second > m[greater].second) {
            greater = j;
            indx = greater;
        }
    }
    if(indx == 0) {
      m[i].first = key;
      m[i].second = value;
    
      if (m[greater].second < m[i].second) {
        greater = i;
      }
    }
  }

  cout << m[greater].first << endl;
}