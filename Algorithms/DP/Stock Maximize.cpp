#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 2e5 + 5;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    //freopen("input.txt", "r", stdin);

    int t, n;

    cin >> t;

    while (t--)
    {
        cin >> n;

        LL pr[n];

        for (int i = 0; i < n; i++)
            cin >> pr[i];

        LL cur = -1, ans = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            if (pr[i] > cur)
                cur = pr[i];
            else
                ans += (cur - pr[i]);
        }

        cout << ans << endl;
    }

    return 0;
}
