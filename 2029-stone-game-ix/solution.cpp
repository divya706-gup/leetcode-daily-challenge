class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int a=0;
        int b=0;
        int c=0;
        for(int s:stones){
            if(s%3==0){
                a++;
            }
            else if(s%3==1){
                b++;
            }
            else{
                c++;
            }
        } 
        if(a%2==0){
            return b>0 && c>0;
        }
        return abs(b-c)>2;
    }
};