#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 1e5 + 5;
int t, n;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<LL> H(n + 1, 0), pref(n + 1, 0);

        for (int i = 1; i <= n; i++)
            cin >> H[i];

        sort(H.begin(), H.end());

        pref[0] = 0;
        for (int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + H[i];

        LL ans = -1;

        for (int i = 0; i <= n; i++)
        {
            LL cur = (i + 1) * (pref[n] - pref[i]);
            ans = max(ans, cur);
        }

        cout << ans << endl;
    }

    return 0;
}
