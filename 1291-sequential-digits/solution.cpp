class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>numbers;
        int min_len=to_string(low).length();
        int max_len=to_string(high).length();
        string sample = "123456789";
        for(int len=min_len;len<=max_len;++len){
            for(int i=0;i<=9-len;++i){
                string sub = sample.substr(i, len);
                int num = stoi(sub);
                if (num >= low && num <= high) {
                    numbers.push_back(num);
                }
            }
        }
         return numbers;
    }
};