class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int>prefix(n+1,0);
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+stones[i-1];
        }
        long long dp=prefix[n];
        for(int i=n-1;i>=2;i--){
            dp=max(dp,prefix[i]-dp);
        }
        return dp;
    }
};