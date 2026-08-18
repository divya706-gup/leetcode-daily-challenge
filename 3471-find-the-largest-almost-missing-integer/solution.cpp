class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        int ans=-1;
        if(k==1){
           for(auto m:mp){
             int a=m.first;
             int b=m.second;
             if(b==1){
                ans=max(ans,a);
             }
           } 
        }
        else if(k==n){
            ans= *max_element(nums.begin(),nums.end());
        }
        else{
            int freq_first=mp[nums[0]];
            int freq_last=mp[nums[n-1]];
            if(freq_first==1&&freq_last==1){
                ans=max(nums[0],nums[n-1]);
            }
            else if(freq_first==1){
                ans= nums[0];
            }
            else if(freq_last==1){
                ans=nums[n-1];
            }
            else{
                ans=-1;
            }
        }
        return ans;
    }
};