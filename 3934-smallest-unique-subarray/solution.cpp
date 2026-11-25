class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        vector<int> rank(n), temp(n), sa(n);
        for (int i = 0; i < n; i++) {
            rank[i] = lower_bound(vals.begin(), vals.end(), nums[i])
                      - vals.begin();
            sa[i] = i;
        }
        for (int k = 1; k < n; k *= 2) {
            sort(sa.begin(), sa.end(), [&](int a, int b) {
                if (rank[a] != rank[b]){
                    return rank[a] < rank[b];
                }
                int ra = (a + k < n) ? rank[a + k] : -1;
                int rb = (b + k < n) ? rank[b + k] : -1;
                return ra < rb;
            });
            temp[sa[0]] = 0;
            for (int i = 1; i < n; i++) {
                int a = sa[i - 1];
                int b = sa[i];

                pair<int, int> x = {
                    rank[a],
                    (a + k < n) ? rank[a + k] : -1
                };
                pair<int, int> y = { rank[b], (b + k < n) ? rank[b + k] : -1};
                temp[b] = temp[a] + (x != y);
            }
            rank = temp;
            if (rank[sa[n - 1]] == n - 1)
                break;
        }
        vector<int> pos(n);

        for (int i = 0; i < n; i++)
            pos[sa[i]] = i;
        vector<int> lcp(n, 0);

        int h = 0;

        for (int i = 0; i < n; i++) {
            int r = pos[i];

            if (r == 0) {
                h = 0;
                continue;
            }

            int j = sa[r - 1];

            while (i + h < n && j + h < n &&
                   nums[i + h] == nums[j + h]) {
                h++;
            }

            lcp[r] = h;

            if (h > 0)
                h--;
        }

        int ans = n;

        for (int i = 0; i < n; i++) {
            int r = pos[i];

            int mx = lcp[r];

            if (r + 1 < n)
                mx = max(mx, lcp[r + 1]);

            int len = mx + 1;

            if (i + len <= n)
                ans = min(ans, len);
        }

        return ans;
    }
};