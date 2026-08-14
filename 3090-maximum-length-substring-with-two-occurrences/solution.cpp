class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.length();
        int left=0;
        int maxLen=0;
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
           mp[s[i]]++;
           while(mp[s[i]]>2){
            mp[s[left]]--;
            left++;
           }
           maxLen=max(maxLen,i-left+1);
        }
       
        return maxLen;
    }
};