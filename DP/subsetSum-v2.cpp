#include <bits/stdc++.h>

//You can reuse the numbers as needed
using namespace std;

const int N = 1000;

int a[N], n;

vector<vector<int>> memo;

bool subsetSum(int idx, int sum)
{
    if (idx == -1)
        return (sum == 0);

    if(memo[idx][sum]!=-1)
        return memo[idx][sum];

    bool ans = false;

    if (sum >= a[idx])
    {
        ans |= subsetSum(idx, sum - a[idx]);
    }

    ans |= subsetSum(idx - 1, sum);

    return memo[idx][sum]=ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int sum;
    cin >> sum >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    
    memo.resize(n, vector<int>(sum + 1, -1));
    cout << subsetSum(n - 1, sum);

    return 0;
}