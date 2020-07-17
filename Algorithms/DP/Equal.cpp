#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 1e4 + 5;
int t, a, b, c, d, n, m, k, p, q, x, y, ans;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> t;

    while (t--)
    {
        cin >> n;

        int arr[n];

        int mn = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mn = min(mn, arr[i]);
        }

        int ans = INT_MAX;

        for (int m = mn; m >= mn - 5; m--)
        {
            int mov = 0;
            for (int i = 0; i < n; i++)
            {
                int temp = arr[i] - m;
                mov += temp / 5 + (temp % 5) / 2 + (temp % 5) % 2;
            }
            ans = min(ans, mov);
        }

        cout << ans << endl;
    }

    return 0;
}
