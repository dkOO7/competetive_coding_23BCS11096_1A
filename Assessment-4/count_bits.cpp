#include <bits/stdc++.h>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
void solve() {
    // Place your problem-solving logic here.
    int n ;
    cin>>n;
    vector<int> v(n);
    for(int i =0;i<n;i++)cin>>v[i];

    vector<int> f(32,0);
    int ans =0;
    for(int k =0;k<n;k++){
        int i = v[k];
        for(int j=0;j<31;j++){
            if(i& (1<<j)){
                f[j]++;
            }
            if(i& (1<<j)){
                ans += (k+1-f[j]);
            }
            else{
                ans += f[j];
            }

        }
    }
    cout<<2*ans;
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
