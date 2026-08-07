class Solution {
public:
    int f[10][4] = {
        {0,0,0,0},
        {0,0,0,0},
        {1,0,0,0},
        {0,1,0,0},
        {2,0,0,0},
        {0,0,1,0},
        {1,1,0,0},
        {0,0,0,1},
        {3,0,0,0},
        {0,2,0,0}
    };

    int need(int a, int b, int c, int d) {
        a = max(0, a);
        b = max(0, b);
        c = max(0, c);
        d = max(0, d);

        int ans = c + d;
        int best = INT_MAX;

        for (int six = 0; six <= 1; six++) {
            int x = max(0, a - six);
            int y = max(0, b - six);

            int cur = six;

            cur += x / 3;
            x %= 3;

            cur += y / 2;
            y %= 2;

            if (x > 0) cur++;
            if (y > 0) cur++;

            best = min(best, cur);
        }

        return ans + best;
    }

    string build(int len, int a, int b, int c, int d) {
        string ans;

        for (int i = 0; i < len; i++) {
            for (int digit = 1; digit <= 9; digit++) {

                int na = max(0, a - f[digit][0]);
                int nb = max(0, b - f[digit][1]);
                int nc = max(0, c - f[digit][2]);
                int nd = max(0, d - f[digit][3]);

                if (need(na, nb, nc, nd) <= len - i - 1) {
                    ans += char('0' + digit);

                    a = na;
                    b = nb;
                    c = nc;
                    d = nd;

                    break;
                }
            }
        }

        return ans;
    }

    string smallestNumber(string num, long long t) {
        int req[4] = {0, 0, 0, 0};
        int prime[4] = {2, 3, 5, 7};

        for (int i = 0; i < 4; i++) {
            while (t % prime[i] == 0) {
                req[i]++;
                t /= prime[i];
            }
        }

        if (t != 1)
            return "-1";

        int n = num.size();

        vector<array<int,4>> pre(n + 1);
        vector<int> zero(n + 1, 0);

        pre[0] = {0, 0, 0, 0};

        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i];
            zero[i + 1] = zero[i];

            int digit = num[i] - '0';

            if (digit == 0) {
                zero[i + 1]++;
            } 
            else {
                for (int j = 0; j < 4; j++)
                    pre[i + 1][j] += f[digit][j];
            }
        }

        if (zero[n] == 0) {
            bool ok = true;

            for (int j = 0; j < 4; j++) {
                if (pre[n][j] < req[j]) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                return num;
        }

        for (int i = n - 1; i >= 0; i--) {

            if (zero[i] > 0)
                continue;

            int start = max(1, num[i] - '0' + 1);

            for (int digit = start; digit <= 9; digit++) {

                int a = max(0, req[0] - pre[i][0] - f[digit][0]);
                int b = max(0, req[1] - pre[i][1] - f[digit][1]);
                int c = max(0, req[2] - pre[i][2] - f[digit][2]);
                int d = max(0, req[3] - pre[i][3] - f[digit][3]);

                int left = n - i - 1;

                if (need(a, b, c, d) <= left) {
                    string ans = num.substr(0, i);

                    ans += char('0' + digit);
                    ans += build(left, a, b, c, d);

                    return ans;
                }
            }
        }

        int len = n + 1;

        while (need(req[0], req[1], req[2], req[3]) > len)
            len++;

        return build(
            len,
            req[0],
            req[1],
            req[2],
            req[3]
        );
    }
};