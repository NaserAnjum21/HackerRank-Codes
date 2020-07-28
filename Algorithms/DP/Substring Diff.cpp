/* passes 8/9 cases, TLE on 1 case */

#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 1502;

int tc, n, k;
string s, t;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    cin >> tc;

    while (tc--)
    {
        cin >> k >> s >> t;
        n = s.size();

        int ans = 0;

        for (int i = 0; i < n - ans; i++)
        {
            for (int j = 0; j < n - ans; j++)
            {
                int mis = 0;
                for (int l = 1; l <= n + 1; l++)
                {
                    if (i + l - 1 >= n or j + l - 1 >= n or mis > k)
                    {
                        ans = mis > k ? max(ans, l - 2) : max(ans, l - 1);
                        break;
                    }
                    if (s[i + l - 1] != t[j + l - 1])
                        mis++;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
