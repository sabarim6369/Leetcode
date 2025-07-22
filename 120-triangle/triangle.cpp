class Solution {
public:
    // int helper(vector<vector<int>>&triangle,int m,int i,int
    // j,vector<vector<int>>&dp){ if(i==m-1){
    //     return triangle[i][j];
    // }
    // if(dp[i][j]!=-1)return dp[i][j];
    // int n=i+1;
    // int movetoindexionnextrow=triangle[i][j]+helper(triangle,m,i+1,j,dp);
    // int movetoindexi1onnextrow=triangle[i][j]+helper(triangle,m,i+1,j+1,dp);
    // return dp[i][j]=min(movetoindexionnextrow,movetoindexi1onnextrow);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        for (int i = 0; i < m; i++) {
            dp[m - 1][i] = triangle[m - 1][i];
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                int movetoindexionnextrow = triangle[i][j] + dp[i + 1][j];
                int movetoindexi1onnextrow = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(movetoindexionnextrow, movetoindexi1onnextrow);
            }
        }
        return dp[0][0];
    }
};