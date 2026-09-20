class Solution {
public:
    int reverseDegree(string s) {
        int degree=0;
       
        for(int i=1;i<=s.length();i++){
            int product =i*(26-(s[i-1]-'a'));
            degree += product;
        }
        return degree;
    }
};