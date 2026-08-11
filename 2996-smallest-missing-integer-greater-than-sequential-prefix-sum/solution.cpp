class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        long long ans=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                ans += nums[i];
            }
            else{
                break;
            }
        }
        unordered_set<int> st(nums.begin(), nums.end());
        while(st.count(ans)){
            ans++;
        }
        return ans;
    }
};