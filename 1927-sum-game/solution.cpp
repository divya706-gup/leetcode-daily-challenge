class Solution {
public:
    bool sumGame(string num) {
        int leftSum = 0, rightSum = 0;
        int n = num.length();
        int leftq = 0, rightq = 0;
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') {
                leftq++;
            } else {
                leftSum += num[i] - '0';
            }
        }
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') {
                rightq++;
            } else {
                rightSum += num[i] - '0';
            }
        }
        if(rightq==leftq){
            return leftSum!=rightSum;
        }
        int a=leftq-rightq;
        int b=leftSum-rightSum;
        if(abs(a)%2==1){
            return true;
        }
       return b != -a * 9 / 2;;
    }
};