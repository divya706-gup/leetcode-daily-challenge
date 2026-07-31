class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        const int MAX=200;
        const int MOD=1e9+7;
        int n=nums.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(MAX+1,vector<int>(MAX+1,0)));
        dp[0][0][0]=1;
        for(int i=0;i<n;i++){
            int x=nums[i];
            for(int g1=0;g1<=MAX;g1++){
                for(int g2=0;g2<=MAX;g2++){
                    if(dp[i][g1][g2]==0){
                        continue;
                    }
                    dp[i+1][g1][g2]=( dp[i+1][g1][g2]+ dp[i][g1][g2])%MOD;
                    int seq1=gcd(g1,x);
                    dp[i+1][seq1][g2]=( dp[i+1][seq1][g2]+ dp[i][g1][g2])%MOD;
                    int seq2=gcd(g2,x);
                     dp[i+1][g1][seq2]=( dp[i+1][g1][seq2]+ dp[i][g1][g2])%MOD;
                }
            }
        }
        int ans=0;
        for(int g=1;g<=200;g++){
            ans = (ans + dp[n][g][g])%MOD;
        }
        return ans;
    }
};