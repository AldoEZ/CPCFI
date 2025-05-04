// longest increasing subsequence
#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(),v.end()			
#define sz(a) int(a.size())
typedef long long ll;
typedef vector<ll> vll;

ll lis(vll& arr) {
    ll n = sz(arr);
    vll lis(n,1);
    
    for(ll i = 1; i < n; i++)
        for(ll prev = 0; prev < i; prev++) {
            if(arr[i] > arr[prev] && lis[i] < lis[prev]+1)
                lis[i] = lis[prev]+1;
        }
    for(auto i : lis) cout << i << " ";
    cout << '\n';
    return *max_element(all(lis));
}
