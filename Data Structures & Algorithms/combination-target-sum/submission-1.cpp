class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<int> currList;
        dfs(nums, target, currList, 0, 0);
        return out;
    }

private:
    vector<vector<int>> out;

    void dfs(vector<int>& nums, int target, vector<int> currList, int currSum, int i) {
        if (currSum == target) {
            out.push_back(currList);
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            if (currSum + nums[j] > target) return;
            currList.push_back(nums[j]);
            dfs(nums, target, currList, currSum + nums[j], j);
            currList.pop_back();
        }
    }
};
