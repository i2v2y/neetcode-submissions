class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxh;
        for (int s : stones) maxh.push(s);
        
        while (maxh.size() > 1) {
            int s1 = maxh.top();
            maxh.pop();
            int s2 = maxh.top();
            maxh.pop();

            if (s1 != s2) maxh.push(s1 - s2);
        }

        maxh.push(0);
        return maxh.top();
    }
};
