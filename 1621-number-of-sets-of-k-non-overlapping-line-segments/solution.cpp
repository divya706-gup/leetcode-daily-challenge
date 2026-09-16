class Solution {
public:
    const long long MOD=1e9+7;
    vector<vector<long long>>dp;
    long long solve(int n,int k){
        if(k==0||k==n){
            return 1;
        }
        if(dp[n][k]!=-1){
            return dp[n][k];
        }
        return dp[n][k]=(solve(n-1,k-1)+solve(n-1,k))%MOD;
    }
    int numberOfSets(int n, int k) {
        int N=n+k-1;
        int R=2*k;
        dp.assign(N+1,vector<long long>(R+1,-1));
        return solve(N,R);
    }
};