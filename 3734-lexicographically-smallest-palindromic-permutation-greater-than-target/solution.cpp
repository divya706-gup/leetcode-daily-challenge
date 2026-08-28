class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int cnt[26] = {};

        for (char c : s)
            cnt[c - 'a']++;

        int odd = 0, mid = -1;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = i;
            }
        }

        if (odd > 1)
            return "";

        int half[26];

        for (int i = 0; i < 26; i++)
            half[i] = cnt[i] / 2;

        int m = n / 2;

        auto build = [&](string left) {
            string ans = left;

            if (n % 2)
                ans += char('a' + mid);

            reverse(left.begin(), left.end());
            ans += left;

            return ans;
        };

        bool possible = true;
        int rem[26];

        for (int i = 0; i < 26; i++)
            rem[i] = half[i];

        string left = "";

        for (int i = 0; i < m; i++) {
            int c = target[i] - 'a';

            if (rem[c] == 0) {
                possible = false;
                break;
            }

            rem[c]--;
            left += target[i];
        }

        if (possible) {
            string ans = build(left);

            if (ans > target)
                return ans;
        }

        for (int pos = m - 1; pos >= 0; pos--) {
            int rem2[26];

            for (int i = 0; i < 26; i++)
                rem2[i] = half[i];

            bool ok = true;

            for (int i = 0; i < pos; i++) {
                int c = target[i] - 'a';

                if (rem2[c] == 0) {
                    ok = false;
                    break;
                }

                rem2[c]--;
            }

            if (!ok)
                continue;

            int x = target[pos] - 'a';

            for (int c = x + 1; c < 26; c++) {
                if (rem2[c] == 0)
                    continue;

                string newLeft = target.substr(0, pos);
                newLeft += char('a' + c);
                rem2[c]--;

                for (int j = 0; j < 26; j++) {
                    while (rem2[j] > 0) {
                        newLeft += char('a' + j);
                        rem2[j]--;
                    }
                }

                return build(newLeft);
            }
        }

        return "";
    }
};