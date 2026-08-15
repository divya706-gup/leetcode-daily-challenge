class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int XOR=0;
        bool non_zero=false;
        for(int nu:nums){
            XOR ^=nu;
            if(nu!=0){
                non_zero=true;
            }
        }
        if(XOR!=0){
            return n;
        }
        if(non_zero){
            return n-1;
        }
        return 0;
    }
};