class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char t : tasks) count[t - 'A']++;

        priority_queue<int> maxh;
        for (int c : count) if (c > 0) maxh.push(c);

        queue<pair<int, int>> cooldown;
        int time = 0;

        while (!maxh.empty() or !cooldown.empty()) {
            time++;
            if (!maxh.empty()) {
                int c = maxh.top() - 1;
                maxh.pop();
                if (c > 0) cooldown.push({c, time + n});
            } else {
                time = cooldown.front().second;
            }

            if (!cooldown.empty() and cooldown.front().second == time) {
                maxh.push(cooldown.front().first);
                cooldown.pop();
            }
        }

        return time;
    }
};
