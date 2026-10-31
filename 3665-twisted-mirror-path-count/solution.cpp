class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int mod=1e9+7;
        vector<int>dp(grid[0].size());
        dp[0]=1;
        for(auto& row:grid){
            int right=0;
            for(int j=0;j<row.size();j++){
                if(row[j]){
                    swap(right,dp[j]);
                }
                else{
                    right=dp[j]=(right+dp[j])%mod;
                }
            }
        }
        return dp.back();
    }
};