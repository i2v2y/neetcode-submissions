class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hm;

        for (const string& s : strs) {
            string count(26, '0');
            for (const char& c : s) count[c - 'a']++;
            hm[count].push_back(s);
        }

        vector<vector<string>> out;
        for (const auto& pair : hm) {
            out.push_back(pair.second);
        }
        
        return out;
    }
};
