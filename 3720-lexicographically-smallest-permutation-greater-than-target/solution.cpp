class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        unordered_map<char, int> mp;

        for (char c : s)
            mp[c]++;

        for (int i = 0; i < target.size(); i++) {
            if (mp[target[i]] > 0) {
                mp[target[i]]--;
            } else {
                char bigger = '{';

                for (char c = target[i] + 1; c <= 'z'; c++) {
                    if (mp[c] > 0) {
                        bigger = c;
                        break;
                    }
                }

                if (bigger != '{') {
                    string ans = target.substr(0, i);
                    ans += bigger;
                    mp[bigger]--;

                    for (char c = 'a'; c <= 'z'; c++) {
                        while (mp[c] > 0) {
                            ans += c;
                            mp[c]--;
                        }
                    }

                    return ans;
                }

                break;
            }
        }

        for (int i = target.size() - 1; i >= 0; i--) {
            mp.clear();

            for (char c : s)
                mp[c]++;

            bool possible = true;

            for (int j = 0; j < i; j++) {
                if (mp[target[j]] == 0) {
                    possible = false;
                    break;
                }
                mp[target[j]]--;
            }

            if (!possible)
                continue;

            for (char c = target[i] + 1; c <= 'z'; c++) {
                if (mp[c] > 0) {
                    string ans = target.substr(0, i);
                    ans += c;
                    mp[c]--;

                    for (char x = 'a'; x <= 'z'; x++) {
                        while (mp[x] > 0) {
                            ans += x;
                            mp[x]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};