class Solution {
public:
    int countCommas(int n) {
        int s=1;
        int e=n;
        int count=0;
        for(int i=s;i<=e;i++){
            if(i>=1000){
                count++;
            }
        }
        return count;
    }
};