// ═══════════════════════════════════════════════════════
// Problem: 3859. Maximum Product of Two Digits
// Difficulty: Easy
// Topics: Math, Sorting
// Runtime: 3 ms (Beats 15.0%)
// Memory: 9.7 MB (Beats 5.9%)
// Submitted: Jul 25, 2026
// Link: https://leetcode.com/problems/maximum-product-of-two-digits/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    int maxProduct(int n) {
        string st=to_string(n);
        vector<int>ans;
        for(auto ch:st){
            ans.push_back(ch-'0');
        }
        int maxProduct=0;
        for(int i=0;i<ans.size()-1;i++){
            for(int j=i+1;j<ans.size();j++){
             
             maxProduct=max(ans[i]*ans[j],maxProduct);
        }
        }
        return maxProduct;
    }
};
