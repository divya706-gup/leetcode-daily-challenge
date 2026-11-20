class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
         ranges::sort(nums);
        vector<int>dp(nums.back()+2);
        for (int x : nums) {
            dp[x + 1] = dp[x] + 1;  
            dp[x] = dp[x - 1] + 1; 
        }
        return ranges::max(dp);
    }
};