#include <bits/stdc++.h>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// #define int long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
void solve() {
    // Place your problem-solving logic here.
    int n ;
    cin >> n ;
    vector<pair<int,int >> nums(n);
    for(int i =0;i<n;i++){
        int u , v ;
        cin >> u >> v;
        nums[i] = {u,v};
    }

    int sum = 0;
    for(auto i : nums){
        sum += i.first;
    }
    int  temp = sum ;
    sort(nums.rbegin(), nums.rend(), [](auto &a ,auto &b){
        if(a.first == b.first){
            return a.second>b.second;
        }
        return a.first<b.first;
    });

    int val = 0;
    for(auto i : nums){
        if(temp >= i.second)temp -= i.first;
        else{
            val += abs(temp -i.second);
        }
    }
    cout<< sum + abs(val);
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
