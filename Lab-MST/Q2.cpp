#include <bits/stdc++.h>
using namespace std;

#define jack420 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void solve() {

    int n;
    cin >> n;

    vector<string> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int ans = INT_MIN;
    map<int,int> mp;

    for(auto cur : v){
        int mask = 0;
        for(auto c : cur){
            int val = c - 'a';
            mask |= (1 << val);
        }
        for(auto j : mp){
            if((j.first & mask) == 0){
                ans = max(ans, (int)cur.size() * j.second);
            }
        }
        mp[mask] = max(mp[mask], (int)cur.size());
    }
    cout << (ans == INT_MIN ? -1 : ans);
}

int main() {

    jack420

    int t;
    cin >> t;

    while(t--){
        solve();
        cout << endl;
    }
}
