#include <bits/stdc++.h>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
void solve() {
    // Place your problem-solving logic here.
    int n , e;
    cin>> n >> e;
    vector<vector<int>> mat(n+1, vector<int>(n+1, INT_MAX));
    for(int i =0;i<e;i++){
        int u , v , w;
        cin >> u >> v >> w;
        mat[u][v] = w;
        mat[v][u] = w;
    }
    for(int i =1;i <=n;i++){
        mat[i][i]=0;
    }

    for(int k = 1; k <= n ; k++ ){
        for(int i = 1 ; i <= n ; i++ ){
            for(int j = 1; j <= n ; j ++){
                if(mat[i][k] != INT_MAX && mat[k][j] != INT_MAX){
                    mat[i][j] = min ( mat[i][j], mat[i][k]+ mat[k][j]);
                }
            }
        }
    }



    //  dist mat;

    for(int i = 1 ; i <=n ; i++){
        for(int j= 1 ; j <= n ; j++){
            cout<<mat[i][j];
        }
        cout<<endl;
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
