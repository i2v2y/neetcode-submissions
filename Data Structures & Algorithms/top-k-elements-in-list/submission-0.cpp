class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int n : nums) count[n]++;

        vector<vector<int>> freq(nums.size() + 1);
        for (const auto& [n, c] : count) freq[c].push_back(n);

        vector<int> out;
        for (int i = freq.size() - 1; i > 0; i--) {
            for (int n : freq[i]) {
                out.push_back(n);
                if (out.size() == k) return out;
            }
        }

        return out;    
    }
};
