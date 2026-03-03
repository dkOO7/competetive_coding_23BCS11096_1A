#include <bits/stdc++.h>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
void solve() {
    // Place your problem-solving logic here.
    int n ;
    cin>> n;
    vector<vector<int>> adj(n+1);
    for(int i =1 ;i<n;i++){
        int u ;
        cin>> u;

        adj[u].push_back(i+1);
    }

    for(int i =0;i<n-1;i++){
        cout<<i+1<<endl;
        for(auto j : adj[i+1]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }
    return 0;
}
