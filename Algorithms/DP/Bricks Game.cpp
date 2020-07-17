#include <bits/stdc++.h>
#define LL long long

#define Min(a, b, c) min(a, min(b, c))
#define Max(a, b, c) max(a, max(b, c))

using namespace std;

const int N = 1e5 + 5;
int arr[N];
LL dp[N];
int t, n;

LL Foo(int i)
{
    if (i > n)
        return 0;
    if (i == n - 1)
        return dp[i] = arr[n];
    if (i == n - 2)
        return dp[i] = arr[n] + arr[n - 1];
    if (i == n - 3)
        return dp[i] = arr[n] + arr[n - 1] + arr[n - 2];

    if (dp[i] != -1)
        return dp[i];

    LL ret1, ret2, ret3;
    ret1 = arr[i + 1] + Min(Foo(i + 2), Foo(i + 3), Foo(i + 4));
    ret2 = arr[i + 1] + arr[i + 2] + Min(Foo(i + 3), Foo(i + 4), Foo(i + 5));
    ret3 = arr[i + 1] + arr[i + 2] + arr[i + 3] + Min(Foo(i + 4), Foo(i + 5), Foo(i + 6));

    return dp[i] = Max(ret1, ret2, ret3);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> t;

    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        memset(dp, -1, sizeof(dp));

        cout << Foo(0) << endl;
    }

    return 0;
}
