class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int out = nums[0];
        int maxp = 1, minp = 1;
        
        for (int n : nums) {
            int tmp = maxp * n;
            maxp = max(n, max(maxp * n, minp * n));
            minp = min(n, min(tmp, minp * n));
            out = max(out, maxp);
        }

        return out;
    }
};
