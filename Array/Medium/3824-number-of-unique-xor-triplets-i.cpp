// ═══════════════════════════════════════════════════════
// Problem: 3824. Number of Unique XOR Triplets I
// Difficulty: Medium
// Topics: Array, Math, Bit Manipulation
// Runtime: 0 ms (Beats 100.0%)
// Memory: 198.7 MB (Beats 85.0%)
// Submitted: Jul 23, 2026
// Link: https://leetcode.com/problems/number-of-unique-xor-triplets-i/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<=2){
            return n;
        }
        int p=1;
        while(p<=n){
            p<<=1;
        }
        return p;
    }
};
