class Solution {
public:
    bool checkDivisibility(int n) {
        string str=to_string(n);
        int sum=0;
        int product=1;
        bool ans=false;
        for(int i=0;i<str.length();i++){
            
            sum += str[i]-'0';
            product *= str[i]-'0';
        
        }
        if(n%(sum+product)==0){
          ans=true;
        }
        return ans;
    }
};