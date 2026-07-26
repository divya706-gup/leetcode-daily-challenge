// ═══════════════════════════════════════════════════════
// Problem: 628. Maximum Product of Three Numbers
// Difficulty: Easy
// Topics: Array, Math, Sorting
// Runtime: 11 ms (Beats 37.4%)
// Memory: 31.4 MB (Beats 76.4%)
// Submitted: Jul 26, 2026
// Link: https://leetcode.com/problems/maximum-product-of-three-numbers/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        // Product of three largest numbers
        int option1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        
        // Product of two smallest (negatives) and the largest number
        int option2 = nums[0] * nums[1] * nums[n - 1];
        
        return max(option1, option2);
    }
};
