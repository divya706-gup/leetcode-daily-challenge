class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        if(n%2!=0){
            return false;
        }
        vector<int>dp(piles.begin(),piles.end());
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                dp[j]=max(piles[i]-dp[j-1],piles[j]-dp[j]);
            }
        }
        return true;
    }
};