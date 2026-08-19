class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> mp;
        for (auto& seat : reservedSeats) {
            mp[seat[0]].insert(seat[1]);
        }
        int ans = 2 * (n - mp.size());
        for (auto& [row, seat] : mp) {
            bool left = true;
            bool middle = true;
            bool right = true;
            for (int s = 2; s <= 5; s++) {
                if (seat.count(s)) {
                    left = false;
                    break;
                }
            }
            for (int s = 4; s <= 7; s++) {
                if (seat.count(s)) {
                    middle = false;
                    break;
                }
            }
            for (int s = 6; s <= 9; s++) {
                if (seat.count(s)) {
                    right = false;
                    break;
                }
            }
            if (left && right) {
                ans += 2;
            } else if (left || middle || right) {
                ans += 1;
            }
        }
        return ans;
    }
};