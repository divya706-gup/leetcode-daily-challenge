class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int k = reduce(nums.begin(), nums.end()) - x;
        int n = nums.size();
        if (k == 0) {
            return n;
        }
        if (k < 0) {
            return -1;
        }

        int a = -1, sum = 0;
        int i = 0;
        for (int j = 0; j < n; j++) {
            sum += nums[j];
            while (sum > k) {
                sum -= nums[i++];
            }
            if (sum == k) {
                a = max(a, j - i + 1);
            }
        }
        return a + 1 ? n - a : -1;
    }
};