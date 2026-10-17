
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        vector<pair<pair<int, int>, int>> s;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int sum = 0;
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            s.push_back({{sum, nums[i]}, i});
        }
        sort(s.begin(), s.end());
        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            pos[s[i].second] = i;
        }
        vector<bool> visited(n, false);
        int number_of_cycles = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]){
                continue;
            }
            int j = i;
            int cycle_size = 0;
            while (!visited[j]) {
                visited[j] = true;
                j = pos[j];
                cycle_size++;
            }
            if (cycle_size > 1){
                number_of_cycles += cycle_size - 1;
            }
        }
        return number_of_cycles;
    }
};
