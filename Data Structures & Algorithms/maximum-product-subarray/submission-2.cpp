class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int out = nums[0];
        int maxp = 1, minp = 1;
        
        for (int n : nums) {
            if (n < 0) swap(maxp, minp);
            maxp = max(n, maxp * n);
            minp = min(n, minp * n);
            out = max(out, maxp);
        }

        return out;
    }
};
