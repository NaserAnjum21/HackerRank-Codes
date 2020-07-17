#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 1e4 + 5;
int t, a, b, c, d, n, m, k, p, q, x, y, ans;

LL maxSubArray(vector<LL> arr)
{
    LL cur_mx = arr[0];
    LL mx = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        cur_mx = max(arr[i], cur_mx + arr[i]);
        mx = max(mx, cur_mx);
    }
    return mx;
}

LL maxSubSequence(vector<LL> arr)
{
    LL mx = arr[0];
    LL posSum = 0;

    for (auto a : arr)
    {
        if (a >= 0)
        {
            posSum += a;
            mx = max(mx, posSum);
        }
        mx = max(mx, a);
    }

    return mx;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> t;

    while (t--)
    {
        cin >> n;

        vector<LL> arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << maxSubArray(arr) << " " << maxSubSequence(arr) << endl;
    }

    return 0;
}
