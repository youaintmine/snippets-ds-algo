ll factorial(ll n) {
	if (n == 1 || n == 0)
		return dp[n] = 1;
	
	if (dp[n]) return dp[n];

	return dp[n] = factorial(n - 1) * n;
}

//Iterative CODE : 

int fact(int n) {
   if (n >= 0) {
      result[0] = 1;
      for (int i = 1; i <= n; ++i) {
         result[i] = i * result[i - 1];
      }
      return result[n];
   }
}