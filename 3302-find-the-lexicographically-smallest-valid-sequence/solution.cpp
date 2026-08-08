class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        vector<int>dp(word1.length()+1,0);
        int m=word2.length();
        int n=word1.length();
        for(int i=n-1;i>=0;i--){
            dp[i]=dp[i+1];
            if(dp[i+1]<m && word1[i]==word2[m-dp[i+1]-1]){
                dp[i]=dp[i+1]+1;
            }
            
        }
        vector<int>ans;
        bool value=false;
        int j=0;
        for(int i=0;i<n&&j<m;i++){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            }
            else if(!value && dp[i+1]>=m-j-1){
                ans.push_back(i);
                j++;
                value=true;
            }
        }
        return (ans.size()==m)?ans:vector<int>{};
    }
};