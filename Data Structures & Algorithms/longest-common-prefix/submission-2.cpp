class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];

        for (int i = 0; i < prefix.size(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != prefix[i]) {
                    return prefix.substr(0, i);
                }
            }
        }

        return prefix;
    }
};