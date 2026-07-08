class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.size();
        int ll = 1;
        int idx = 0;

        for (int i = 0; i < n; i++) {
            int l = i;
            int r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            if (r - l - 1 > ll) {
                ll = r - l - 1;
                idx = l + 1;
            }

            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            if (r - l - 1 > ll) {
                ll = r - l - 1;
                idx = l + 1;
            }
        }
        return s.substr(idx, ll);
    }
};
