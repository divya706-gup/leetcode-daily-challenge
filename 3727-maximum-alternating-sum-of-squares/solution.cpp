class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<long long>squ(n);
        for(int i=0;i<n;i++){
            squ[i]=1LL*nums[i]*nums[i];
        }
        sort(squ.begin(),squ.end());
        long long ans=0;
        int k=n/2;
        for(int i=0;i<k;i++){
            ans-=squ[i];
        }
        for(int i=k;i<n;i++){
            ans+=squ[i];
        }
        return ans;
    }
};