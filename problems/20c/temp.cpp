#include <bits/stdc++.h>
using namespace std;
#define int long long
#define jack420 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void solve() {

    int v , e ;
    cin >> v >> e;

    vector<vector<pair<int,int>>> adj(v+1);
    vector<int> parent(v+1,-1);
    parent[1]=-1;
    for(int i = 0 ; i < e ; i++){
        int u , to , w;
        cin >> u >> to >> w;

        adj[u].push_back({to,w});
        adj[to].push_back({u,w});
    }

    vector<int> dist(v+1 , LLONG_MAX);

    dist[1] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0,1});

    while(!pq.empty()){

        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(wt > dist[node]) continue;
        if(node == v)break;

        for(auto it : adj[node]){

            int nei = it.first;
            int nwt = it.second;

            if(dist[node] + nwt < dist[nei]){
                parent[nei] = node;

                dist[nei] = dist[node] + nwt;
                pq.push({dist[nei], nei});
            }
        }
    }

    if(dist[v]==LLONG_MAX){
        cout<<-1;
        return;
    }

    int tg = v;
    vector<int> path;
    while( tg != -1 ){
        path.push_back(tg);
        tg= parent[tg];
    }
    reverse(path.begin(), path.end());
    for(auto i : path){
        cout<<i<<" ";
    }
}

int32_t main() {

    jack420

    int t = 1;
    while (t--) {
        solve();
        cout << endl;
    }

    return 0;
}
