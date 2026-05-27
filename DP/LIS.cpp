
vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
int solve(int i, int P)
{
    if (i >= n)
        return 0;

    if (dp[i][P] != -1)
        return dp[i][P];

    int take = 0;
    if (P == -1 || nums[P] < nums[i])
        take = 1 + solve(i + 1, i);

    int skip = solve(i + 1, P);

    return dp[i][P] = max(take, skip);
}