class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> curr;
        backtrack(nums, curr, 0);
        return out;
    }

private:
    vector<vector<int>> out;

    void backtrack(vector<int>& nums, vector<int>& curr, int i) {
        out.push_back(curr);

        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j-1]) continue;
            curr.push_back(nums[j]);
            backtrack(nums, curr, j + 1);
            curr.pop_back();
        }
    }
};
