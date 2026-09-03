class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int mn = *min_element(nums1.begin(), nums1.end());

        // Minimum is even:
        // parity cannot be changed using mn.
        if (mn % 2 == 0) {
            for (int x : nums1) {
                if (x % 2 != 0)
                    return false;
            }
            return true;
        }

        // Minimum is odd:
        // Every even x > mn can become odd by x - mn.
        return true;
    }
};