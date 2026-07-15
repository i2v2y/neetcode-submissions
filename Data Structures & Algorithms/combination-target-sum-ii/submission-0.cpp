class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> currList;
        dfs(candidates, target, currList, 0, 0);
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
            if (j > i && nums[j] == nums[j-1]) continue;
            if (currSum + nums[j] > target) return;
            currList.push_back(nums[j]);
            dfs(nums, target, currList, currSum + nums[j], j + 1);
            currList.pop_back();
        }
    }        
};
