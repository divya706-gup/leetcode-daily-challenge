class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int max_elem=*max_element(nums.begin(),nums.end());
        int min_elem=*min_element(nums.begin(),nums.end());
        vector<int>result;
        for(int i=min_elem;i<=max_elem;i++){
            if(find(nums.begin(),nums.end(),i)==nums.end()){
                result.push_back(i);
            }
        }
        return result;
    }
};