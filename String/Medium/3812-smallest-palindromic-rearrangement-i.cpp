// ═══════════════════════════════════════════════════════
// Problem: 3812. Smallest Palindromic Rearrangement I
// Difficulty: Medium
// Topics: String, Sorting, Counting Sort
// Runtime: 95 ms (Beats 31.4%)
// Memory: 69.2 MB (Beats 69.2%)
// Submitted: Jul 28, 2026
// Link: https://leetcode.com/problems/smallest-palindromic-rearrangement-i/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.length();
        string half = s.substr(0, n / 2);
        sort(half.begin(),half.end());
        string rev_half=half;
        reverse(rev_half.begin(),rev_half.end());
        if(n%2!=0){
            return half +s[n/2]+rev_half;
        }
        return half + rev_half;
    }
};
