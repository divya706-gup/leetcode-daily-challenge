class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxProduct=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               maxProduct=max(maxProduct,(nums[i]-1)*(nums[j]-1));
            }
        }
        return maxProduct;
    }
};