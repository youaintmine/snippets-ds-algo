#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int sum, n;
    cin >> sum >> n;

    int a[n + 1];
    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    bool dp[n + 1][sum + 1];

    dp[0][0] = true;

    for (int j = 1; j <= sum; j++)
        dp[0][j] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {

            dp[i][j] = dp[i - 1][j];

            if (j >= a[i])
                dp[i][j] |= dp[i - 1][j - a[i]];
        }
    }

    cout << dp[n][sum]<<endl;

    // Trail of DP source

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }
    vector<int> val;
    if(dp[n][sum]){
            int i = n;
            for(int j = sum; j>=0; ){
                if(!dp[i-1][j]){
                    val.push_back(a[i]);
                    j = j - a[i];
                }i--;
            }
    }

    cout<<val;

    return 0;
}
