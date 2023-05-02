// recursion gives TLE , TC : exponential SC : o(N)
//Dp gives TLE as well as TC: O(M X N) SC : O(MXN)+O(N) i.e matrix + stack space
// this question is very similar to that of minimum path sum in grid

class Solution {
private : 
int solve(int i, int j, vector<vector < int>> &matrix, vector< vector< int>> &dp)
        {
            if (j < 0 || j >= matrix[0].size())
            {
                return 1e9;
            }
            if (i == 0)
            {
                return matrix[i][j];
            }
            if (dp[i][j] != -1)
            {
                return dp[i][j];
            }
            int up = matrix[i][j] + solve(i - 1, j, matrix, dp);
            int leftdg = matrix[i][j] + solve(i - 1, j - 1, matrix, dp);
            int rightdg = matrix[i][j] + solve(i - 1, j + 1, matrix, dp);
            return dp[i][j] = min(up, min(leftdg, rightdg));
        }
        public:
    int minFallingPathSum(vector<vector < int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector < int>> dp(n, vector<int> (m, -1));
        int mini = 1e9;
        // loop is run since, for each element of first row
        for (int i = 0; i < m; i++)
        {
            mini = min(mini, solve(n - 1, i, matrix, dp));
        }
        return mini;
    }
};