#include <bits/stdc++.h>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
void solve() {
    // Place your problem-solving logic here.
    int v , e ;
    cin >> v >> e;
    vector<pair<int,pair<int,int>>> adj;
    for(int i =0;i<e ; i++){
        int a , b , w ;
        cin>> a>> b >> w;
        adj.push_back({a,{b,w}});
    }

    vector<int> dist(v+1, INT_MAX);
    dist[1]=0;
    for(int i= 1 ;i <= v-1;i++){
        for(auto it : adj){
            int u =it.first;
            int v = it.second.first;
            int w= it.second.second;
            if(dist[u]+ w < dist[v]){
                dist[v]= dist[u]+ w;
            }
        }
    }

    bool cycle = false;

    for(auto it : edges){

        int u = it.first;
        int v2 = it.second.first;
        int w = it.second.second;

        if(dist[u] != LLONG_MAX && dist[u] + w < dist[v2]){
            cycle = true;
            break;
        }
    }

    if(cycle)
        cout<<"Negative Cycle Exists\n";
    else
        cout<<"No Negative Cycle\n";



    for(int i =1;i<=v;i++){
        cout<<dist[i];
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
