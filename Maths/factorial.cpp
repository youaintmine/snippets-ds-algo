ll factorial(ll n) {
	if (n == 1 || n == 0)
		return dp[n] = 1;
	
	if (dp[n]) return dp[n];

	return dp[n] = factorial(n - 1) * n;
}