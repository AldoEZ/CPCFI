// longest increasing subsequence
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
