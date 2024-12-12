#include <bits/stdc++.h>
#define ll long long
#define fastIo() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    fastIo();
    int a,b,p,A,B;
    string P;
    
    cin >> a >> b >> p;
    cin >> A; cin >> B; cin >> P;
    
    string producto = to_string(A*B);
    int indice = 0;
    
    int i = 0, j = p-1;
    while(1) {
        if(P[i] == '*') {
            indice = i; break;
        } else if(P[j] == '*') {
            indice = j; break;
        }
        i++; j--;
    }
    if(indice == i) cout << producto[i] << endl;
    else cout << producto[j] << endl;
}
