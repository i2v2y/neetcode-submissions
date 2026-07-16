class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxh;

        for (const auto& p : points) {
            maxh.push({p[0] * p[0] + p[1] * p[1], p});
            if (maxh.size() > k) maxh.pop();
        }

        vector<vector<int>> out;
        while (!maxh.empty()) {
            out.push_back(maxh.top().second);
            maxh.pop();
        }

        return out;
    }
};