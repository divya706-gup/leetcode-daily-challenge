// ═══════════════════════════════════════════════════════
// Problem: 3805. Maximize Active Section with Trade I
// Difficulty: Medium
// Topics: String, Enumeration
// Runtime: 98 ms (Beats 32.9%)
// Memory: 151.5 MB (Beats 18.5%)
// Submitted: Jul 21, 2026
// Link: https://leetcode.com/problems/maximize-active-section-with-trade-i/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int initialOnes = 0;
        int n = s.length();
        vector<pair<char, int>> blocks;
        int i = 0;
        while (i < n) {
            char ch = s[i];
            int count = 0;
            while (i < n && s[i] == ch) {
                if (ch == '1') initialOnes++;
                count++;
                i++;
            }
            blocks.push_back({ch, count});
        }
           int maxDelta = 0;
        for (int k = 1; k < (int)blocks.size() - 1; ++k) {
            if (blocks[k].first == '1' && blocks[k - 1].first == '0' && blocks[k + 1].first == '0') {
                maxDelta = max(maxDelta, blocks[k - 1].second + blocks[k + 1].second);
            }
        }
        return initialOnes+maxDelta;
    }
    
};
