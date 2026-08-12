class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
       int ans=0;
       int left=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            while(mp[nums[i]]>k){
                mp[nums[left]]--;
               left++;
            }
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};