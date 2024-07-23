/*
	Time Complexity: O(N * SUM)
	Space Complexity: O(N * SUM)

	Where N is the number of elements in the array and SUM denotes the sum of all the elements in the array.
*/

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum = 0, res = 0, ans = 0;
	// Calculating the sum of all the array elements.
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}

	res = sum;
	if (sum % 2 == 0) {
		sum /= 2;
	}

	else {
		sum = (sum + 1) / 2;
	}

	bool dp[n + 1][sum + 1];
	// Initializing the dp with its initial state.
	memset(dp, false, sizeof(dp));
	for (int i = 0; i <= n; i++) {
		dp[i][0] = true;
	}
	
	// Calculating the value of each state of the dp.
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= sum; j++)
		{
			if (arr[i - 1] > j) {
				dp[i][j] = dp[i - 1][j];
			}

			else {
				dp[i][j] = dp[i - 1][j] | dp[i - 1][j - arr[i - 1]];
			}
		}
	}

	for (int i = sum; i >= 0; i--)
	{
		if (dp[n][i])
		{
			// Here i represents the path sum.
			ans = abs(res - 2 * i);
			break;
		}
	}

	return ans;
}
