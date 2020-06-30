#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 2e5 + 5;
int t, a, b, c, d, n, m, k, p, q, x, y, ans;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    freopen("input.txt", "r", stdin);

    cin >> n >> q;

    vector<vector<int>> vec(n);

    for (int i = 0; i < n; i++)
    {
        cin >> k;

        while (k--)
        {
            cin >> x;
            vec[i].push_back(x);
        }
    }

    while (q--)
    {
        cin >> x >> y;
        cout << vec[x][y] << endl;
    }

    return 0;
}
