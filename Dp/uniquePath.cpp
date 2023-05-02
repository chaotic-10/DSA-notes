/* 
    1. out of bound and first index wala base case check kia
    2.recursively har place pe gaye 
    3. sum up kia all the ways

*/

class Solution {
private:
// time complexity is o( m x n) 
// sc o(m-1 + n-1 )

int func(int i, int j, vector<vector<int>>&dp){
    if(i==0 && j==0){
        return 1;
    }
    //out of bound ke lie check
    if(i<0 || j<0){
        return 0;
    }
    if(dp[i][j] != -1) return dp[i][j];
    // sum all possible ways 
    int up =func(i-1,j,dp);
    int left=func(i,j-1,dp);
    return dp[i][j] =(up+left);
}
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return func(m-1,n-1,dp);
        
    }
};