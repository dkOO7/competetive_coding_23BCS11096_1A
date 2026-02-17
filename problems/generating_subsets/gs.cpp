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
    vector<vector<int>> subs;
    for(int i =0;i<n;i++)cin>>v[i];

    int mask = 1<<n;
    for(int i =0;i<mask;i++){
        int val = i;
        vector<int> temp;
        for(int j =0;j<n;j++){
            if((val & (1<<j))>0){
                temp.push_back(v[j]);
            }
        }
        if(temp.size())subs.push_back(temp);
    }
    for(auto i :subs){
        for(auto j :i)cout<<j<<" ";
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
