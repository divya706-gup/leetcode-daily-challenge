// ═══════════════════════════════════════════════════════
// Problem: 1574. Maximum Product of Two Elements in an Array
// Difficulty: Easy
// Topics: Array, Sorting, Heap (Priority Queue)
// Runtime: 11 ms (Beats 7.6%)
// Memory: 13.4 MB (Beats 85.5%)
// Submitted: Jul 27, 2026
// Link: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
// ═══════════════════════════════════════════════════════

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
