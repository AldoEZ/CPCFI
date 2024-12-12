#include <iostream>
using namespace std;

void solve() {
    int n, k;
    cin >> n;
    cin >> k;
    
    int aux = k / n;
    
    if(n == k) {
        cout << 1 << '\n';
        return;
    }
    if(n == 1) {
        cout << k << '\n';
        return;
    }
    while(1) {
        if((k - (n*aux)) < n) {
            aux--;
        }
        else {
            cout << aux << '\n';
            break;
        }
    }
}

int main() {
    solve();
}
