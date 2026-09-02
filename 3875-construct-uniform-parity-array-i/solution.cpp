class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool odd = false;
        bool even = false;
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] % 2 == 0) {
                even = true;
                odd = false;
            } else {
                odd = true;
                even = true;
            }
        }
        vector<int>nums2(nums1.size());
        if (odd && even) {
            for (int i = 0; i < nums1.size(); i++) {
                int oddEle;
                if (nums1[i] % 2 != 0) {
                    oddEle = nums1[i];
                    nums2[i] = oddEle;
                }
                nums2[i] = nums2[i]-oddEle;
            }
        }
        else{
            nums2=nums1;
        }
        bool odd2=false,even2=true;
        for (int i = 0; i < nums2.size(); i++) {
            if (nums2[i] % 2 == 0) {
                even2 = true;
                odd2 = false;
            } else {
                odd2 = true;
                even2 = true;
            }
        }
        return (odd2)||(even2)||(odd2 && even2);
    }
};