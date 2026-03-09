#include <bits/stdc++.h>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
void solve() {
    // Place your problem-solving logic here.
    int n , e ;
    cin>> n >> e ;
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i =0 ; i < e ; i ++){
        int u , v , w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
    pq.push({0,1});
    vector<int> dist(n+1, INT_MAX);
    dist[1]=0;

    while(!pq.empty()){
        auto [cost , node] = pq.top();
        pq.pop();

        if(cost > dist[node])continue;

        for(auto &[nei, nwt] : adj[node]){
            if( dist[node] + nwt < dist[nei]){
                dist[nei] = dist[node] + nwt;
                pq.push({dist[nei], nei});
            }
        }
    }

    for(int i =1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
}
int32_t main() {
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }
    return 0;
}
