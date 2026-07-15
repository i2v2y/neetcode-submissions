class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hm;

        for (const string& s : strs) {
            string count(26, 0);
            for (char c : s) count[c - 'a']++;
            hm[count].push_back(s);
        }

        vector<vector<string>> out;
        for (auto& [key, group] : hm) {
            out.push_back(group);
        }
        
        return out;
    }
};
