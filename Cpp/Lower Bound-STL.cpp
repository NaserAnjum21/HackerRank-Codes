#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 2e5 + 5;
int t, a, b, c, d, n, m, k, p, q, x, y, ans;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    freopen("input.txt", "r", stdin);

    cin >> n;

    vector<int> vec;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        vec.push_back(x);
    }

    cin >> q;

    while (q--)
    {
        cin >> y;
        vector<int>::iterator lo = lower_bound(vec.begin(), vec.end(), y);
        int pos = lo - vec.begin();

        if (vec[pos] == y)
            cout << "Yes ";
        else
            cout << "No ";
        cout << pos + 1 << endl;
    }

    return 0;
}
