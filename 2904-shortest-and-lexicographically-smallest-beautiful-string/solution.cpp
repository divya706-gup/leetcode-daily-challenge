class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int ans = INT_MAX;
        string str = "";
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == '1') {
                    count++;
                }
                if (count == k) {
                    int len = j - i + 1;
                    string curr = s.substr(i, len);
                    if (len < ans || (len == ans && curr < str)) {
                        ans = len;
                        str = curr;
                    }
                    break;
                }
            }
        }
        return str;
    }
};