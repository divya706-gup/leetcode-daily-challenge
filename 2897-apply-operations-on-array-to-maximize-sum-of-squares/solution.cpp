class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int bits[30]={0};
        long long ans=0,mod=1000000007;
        for(int x:nums){
            for(int i=0;i<30;i++){
                if(x&(1<<i)){
                    bits[i]++;
                }
            }
        }
        while(k){
            long long x=0;
            for(int i=0;i<30;i++){
                if(bits[i]>0){
                    x |= 1LL<<i;
                    bits[i]--;
                }
            }
            ans =(ans+x*x)%mod;
            k--;
        }
        return (int)ans;
    }
};