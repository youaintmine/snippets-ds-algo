/*
This snippet will find msb 
It will divide different bitted numbers differently too.
Will work for upto 10^18
*/

ll dp[32];
map<ll, vector<ll>> mp;
void solve()
{
	for (int i = 0; i <=30; i++) {
		dp[i] = pow(2, i)-1;
	}

	// _print(dp, 30);
	int arr[] = { 1, 2,3,4,5,6,7,8, 11,12,13,14,16 };
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < n; i++)
	{
		cerr << endl;
		int pos = lower_bound(dp, dp + 31, arr[i]) - dp;
		mp[pos].push_back(arr[i]);
	}
	// _print(mp);
}
