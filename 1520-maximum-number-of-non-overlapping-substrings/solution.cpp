class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26, n);
        vector<int> last(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }
        vector<pair<int, int>> intervals;
        for (int c = 0; c < 26; c++) {
            if (last[c] == -1) {
                continue;
            }
            int l = first[c];
            int r = last[c];
            bool valid = true;
            for (int i = l; i <= r; i++) {
                int x = s[i] - 'a';
                if (first[x] < l) {
                    valid = false;
                    break;
                }
                r = max(r, last[x]);
            }
            if (valid) {
                intervals.push_back({r, l});
            }
        }
        sort(intervals.begin(), intervals.end());
        vector<string> result;
        int a = -1;
        for (auto [right, left] : intervals) {
            if (left > a) {
                result.push_back(s.substr(left, right - left + 1));
                a = right;
            }
        }
        return result;
    }
};