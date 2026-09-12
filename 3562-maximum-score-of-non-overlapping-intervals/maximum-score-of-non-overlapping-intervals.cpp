class Solution {
public:
    struct State {
        long long score = 0;
        vector<int> ids;
    };

    vector<vector<int>> a;
    vector<vector<State>> dp;
    vector<int> nxt;
    int n;

    bool better(const State& x, const State& y) {
        if (x.score != y.score)
            return x.score > y.score;

        return x.ids < y.ids;
    }

    State solve(int i, int k) {
        if (i >= n || k == 0)
            return {0, {}};

        if (dp[i][k].score != -1)
            return dp[i][k];
        State skip = solve(i + 1, k);
        State take = solve(nxt[i], k - 1);
        take.score += a[i][2];
        take.ids.push_back(a[i][3]);
        sort(take.ids.begin(), take.ids.end());

        return dp[i][k] = better(take, skip) ? take : skip;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();
        for (int i = 0; i < n; i++)
            intervals[i].push_back(i);

        a = intervals;
        sort(a.begin(), a.end());
        nxt.resize(n);

        for (int i = 0; i < n; i++) {
            nxt[i] = upper_bound(
                a.begin() + i + 1,
                a.end(),
                a[i][1],
                [](int end, const vector<int>& interval) {
                    return end < interval[0];
                }
            ) - a.begin();
        }

        dp.assign(n, vector<State>(5));
        for (auto& row : dp)
            for (auto& state : row)
                state.score = -1;

        return solve(0, 4).ids;
    }
};