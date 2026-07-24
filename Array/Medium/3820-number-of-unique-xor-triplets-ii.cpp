// ═══════════════════════════════════════════════════════
// Problem: 3820. Number of Unique XOR Triplets II
// Difficulty: Medium
// Topics: Array, Math, Bit Manipulation, Enumeration
// Runtime: 932 ms (Beats 59.0%)
// Memory: 35.3 MB (Beats 80.9%)
// Submitted: Jul 24, 2026
// Link: https://leetcode.com/problems/number-of-unique-xor-triplets-ii/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        vector<bool>pairXOR(2048,false);
        for(int j=0;j<n;j++){
            for(int k=j;k<n;k++){
                pairXOR[nums[j]^nums[k]]=true;
            }
        }
        vector<bool>triplet(2048,false);
        for(int i=0;i<n;i++){
            for(int x=0;x<2048;x++){
                if(pairXOR[x]){
                    triplet[x^nums[i]]=true;
                }
            }
        }
        int count=0;
        for(int x=0;x<2048;x++){
            if(triplet[x]){
                count++;
            }
        }
        return count;
    }
};
