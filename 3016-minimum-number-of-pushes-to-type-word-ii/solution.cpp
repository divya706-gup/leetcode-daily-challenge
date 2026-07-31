class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;
        for(auto ch:word){
            mp[ch]++;
        }
        vector<pair<char,int>>v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),[](auto &a,auto &b ){
            return a.second>b.second;
        });
        int totalPushes=0;
        for(int i=0;i<v.size();i++){
            int fact=(i/8)+1;
            totalPushes += v[i].second * fact;
        }
        return totalPushes;
    }
};