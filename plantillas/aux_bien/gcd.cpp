#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gc(ll a, ll b) {
    if(b>a) swap(a,b);
    
    while(b != 0) {
        a = b;
        b = a%b;
    }
    return a;
}
