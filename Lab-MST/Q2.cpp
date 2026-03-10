#include <bits/stdc++.h>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
void solve() {
    // Place your problem-solving logic here.
    int n;
    cin >> n ;
    vector<string> v(n);
    for(int i =0;i<n;i++){
        string s ;
        cin >> s;
        v[i] = s;
    }

    int ans = INT_MIN;
    map<int, int > mp;
    for(auto  i : v){
        string cur = i;
        int mask =0;
        for(auto i : cur){
            int val = i - 'a';
            mask |= (1<<val);
        }
        if(mp.find(!mask) != mp.end()){
            ans = max(ans , cur.size() * mp[!mask] );
        }
        mp[mask]= cur.size();
    }
    cout<<(ans== INT_MIN)?-1: ans;
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
