

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        long long MOD = 1e9 + 7;
        
        // 1. Filter out non-zero digits and track their original indices
        vector<int> digits;
        vector<int> positions;
        
        for (int i = 0; i < m; ++i) {
            if (s[i] != '0') {
                digits.push_back(s[i] - '0');
                positions.push_back(i);
            }
        }
        
        int num_nonzero = digits.size();
        
        // 2. Build Prefix Sum, Prefix Value, and Powers of 10 Arrays
        vector<long long> pref_sum(num_nonzero + 1, 0);
        vector<long long> pref_val(num_nonzero + 1, 0);
        vector<long long> pow10(num_nonzero + 1, 1);
        
        for (int i = 0; i < num_nonzero; ++i) {
            pref_sum[i + 1] = pref_sum[i] + digits[i];
            pref_val[i + 1] = (pref_val[i] * 10 + digits[i]) % MOD;
            pow10[i + 1] = (pow10[i] * 10) % MOD;
        }
        
        // 3. Process Queries
        vector<int> answer;
        answer.reserve(queries.size());
        
        for (const auto& q : queries) {
            int L = q[0];
            int R = q[1];
            
            // Find the first non-zero digit index inside the query boundary [L, R]
            auto it_left = lower_bound(positions.begin(), positions.end(), L);
            // Find the last non-zero digit index inside the query boundary [L, R]
            auto it_right = upper_bound(positions.begin(), positions.end(), R);
            
            int i = distance(positions.begin(), it_left);
            int j = distance(positions.begin(), it_right) - 1;
            
            // Edge Case: If no non-zero digits are within [L, R]
            if (i > j) {
                answer.push_back(0);
                continue;
            }
            
            // Extract the sum of the digits
            long long current_sum = pref_sum[j + 1] - pref_sum[i];
            
            // Extract the concatenated value 'x'
            int segment_len = j - i + 1;
            long long x = (pref_val[j + 1] - (pref_val[i] * pow10[segment_len]) % MOD + MOD) % MOD;
            
            // Calculate final product
            long long result = (x * current_sum) % MOD;
            answer.push_back(result);
        }
        
        return answer;
    }
};