#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 3e5 + 1;
int dp[42];
vector<bool> isPrime(N + 1, true);
int n, t;

void Sieve()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= N; i++)
    {
        if (!isPrime[i])
            continue;
        for (int j = i * i; j <= N; j += i)
            isPrime[j] = false;
    }
}

int CountPrimes(int n)
{
    int count = 0;

    for (int i = 1; i <= n; i++)
        if (isPrime[i])
            count++;

    return count;
}

int CountWays(int x)
{
    if (x == 0)
        return 1;
    if (x < 0)
        return 0;
    if (dp[x] != -1)
        return dp[x];
    return dp[x] = CountWays(x - 1) + CountWays(x - 4);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    Sieve();

    cin >> t;

    while (t--)
    {
        cin >> n;
        memset(dp, -1, sizeof(dp));
        cout << CountPrimes(CountWays(n)) << endl;
    }

    return 0;
}
