class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            string num=to_string(nums[i]);
            int j=0;
            int sum=0;
            while(j<num.size()){
                 sum+=num[j]-'0';
                 j++;
            }
            if(sum==i){
                return i;
            }
        }
        return -1;
    }
};