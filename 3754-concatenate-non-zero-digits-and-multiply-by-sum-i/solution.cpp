class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long x=0;
        string s=to_string(n);
        for(char ch:s){
            if(ch!='0'){
                int digit=ch-'0';
                sum += digit;
                x=x*10+digit;
            }
        }
        return x*sum;
    }
};