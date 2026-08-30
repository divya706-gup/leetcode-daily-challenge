class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minimum=min_element(nums.begin(),nums.end())-nums.begin();
        int maximum=max_element(nums.begin(),nums.end())-nums.begin();
        int minimum_deletions=0;
        if(minimum>maximum){
            swap(minimum,maximum);
        }
        int front=maximum+1;
        int back=nums.size()-minimum;
        int both=(minimum+1)+(nums.size()-maximum);
        return min({front,back,both});
    }
};