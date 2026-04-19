void floydWarshall(vector<vll>& dist, ll n) {
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < n; j++)
            for(ll k = 0; k < n; k++)
                if(dist[j][i] != INF64 && dist[i][k] != INF64)
                    dist[j][k] = min(dist[j][k], dist[j][i]+dist[i][k]);
}
