class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
      vector<int>rank=arr;
      sort(rank.begin(),rank.end());
      unordered_map<int,int>mp; 
       int currRank=1;
       for(auto num:rank){
        if(mp.count(num)==0){
            mp[num]=currRank;
            currRank++;
        }
       } 
       for(int i=0;i<arr.size();i++){
        arr[i]=mp[arr[i]];
       }
       return arr;
    }
};