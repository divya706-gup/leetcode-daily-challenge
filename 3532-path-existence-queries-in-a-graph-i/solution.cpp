class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // comp[i] will store the ID of the connected component that node i belongs to
        vector<int> comp(n, 0);
        int component_id = 0;
        
        // Single pass to partition the sorted array into contiguous components
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                component_id++; // Found a gap larger than maxDiff, start a new component
            }
            comp[i] = component_id;
        }
        
        // Answer each query in O(1) time
        vector<bool> answer;
        answer.reserve(queries.size());
        
        for (const auto& q : queries) {
            int u = q[0];
            int v = q[1];
            // If they share the same component ID, a path exists
            answer.push_back(comp[u] == comp[v]);
        }
        
        return answer;
    }
};