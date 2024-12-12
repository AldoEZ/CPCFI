#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

void crearPrefix(vi& arr, vi& prefix, int n) {
    prefix[0] = arr[0];
    
    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] + arr[i];
    }
}

int main() {    
	vi arr;
    
    arr.push_back(5); arr.push_back(12);
    arr.push_back(7); arr.push_back(14);
    arr.push_back(21); arr.push_back(54);
    
    int n = size(arr);
    
    vi prefix(n);
    crearPrefix(arr, prefix, n);
    
    // cout << "Arreglo Original: ";
    // for(auto i : arr) cout << i << " ";
    
    // cout << "\n   Prefix Sum:    ";
    // for(auto i : prefix) cout << i << " ";
    
    // cout << "\n";
    
    // se requiere saber la suma de el dato 3 al 5 elementos
    // cout << prefix[4] - prefix[1] << endl;
}