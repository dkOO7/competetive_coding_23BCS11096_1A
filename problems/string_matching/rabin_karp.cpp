#include <bits/stdc++.h>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
void solve() {
    // Place your problem-solving logic here.
    string txt ="abcabcabcabc";
    string pat = "abc";
    int n = txt.size(), m = pat.size();
    int q = 101; // prime number
    int p = 0, t = 0, h = 1;
    for (int i = 0; i < m - 1; i++) h = (h * q) % q;
    for (int i = 0; i < m; i++) {
        p = (p * q + pat[i]) % q;
        t = (t * q + txt[i]) % q;
    }
    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            bool flag = true;
            for (int j = 0; j < m; j++) {
                if (txt[i + j] != pat[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) cout << i << " ";
        }
        if (i < n - m) {
            t = (t - txt[i] * h + txt[i + m] * q) % q;
            if (t < 0) t += q;
        }
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
