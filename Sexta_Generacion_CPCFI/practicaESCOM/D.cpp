#include <bits/stdc++.h>
#define ll long long
#define fastIo() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    fastIo();
    int n = 0;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cout << i*4 + 10 << " ";
    }
    cout << '\n';
}
