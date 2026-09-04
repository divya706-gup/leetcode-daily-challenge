class Solution {
public:
    int findMax(vector<int>& nums, int s, int e) {
        int maxi = INT_MIN;
        for (int i = s; i < e; i++) {
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }
    int findMin(vector<int>& nums, int s, int e) {
        int mini = INT_MAX;
        for (int i = s; i < e; i++) {
            mini = min(mini, nums[i]);
        }
        return mini;
    }
    int firstStableIndex(vector<int>& nums, int k) {
        
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            int mx = findMax(nums, 0, i+1);
            int mn = findMin(nums, i, n );
            if (mx - mn <= k) {
                return i;
            }
        }
        return -1;
    }
};