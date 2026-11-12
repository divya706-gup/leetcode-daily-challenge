class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int count=0;
        int n=nums.size(),i=0;
        int dec=1,inc=1;
        if(n==1){
            return n;
        }
        for( i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                inc++;
                dec=1;
            }
            else if(nums[i]<nums[i-1]){
                inc=1;
                dec++;
            }
            else{
                inc=dec=1;
            }
            count=max({count,inc,dec});
        }
        return count;
    }
};