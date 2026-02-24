#include <bits/stdc++.h>
using namespace std;
#define jack420                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
vector<int> res;

void kmp(string text, string word, vector<int> lps)
{
    int n = text.size(), m = word.size();

    int i = 0, j = 0;
    while (i < n)
    {
        if (text[i] == word[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            // found
            res.emplace_back(i - j);
            j = lps[j - 1];
        }
        else if (text[i] != word[j])
        {
            if (j != 0)
                j = lps[j - 1];
            else
            {
                i++;
            }
        }
    }
}
void solve()
{
    // Place your problem-solving logic here.
    string text = "ababcabcababc";
    string word = "abc";
    int n = text.size(), m = word.size();
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;
    while (i < m)
    {
        if (word[i] == word[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    kmp(text, word, lps);
    for (auto i : res)
        cout << i << " ";
}
int32_t main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}
