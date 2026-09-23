class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }
        
        string prefix = "";
        string compare = strs[0]; // average len

        for (int i = 0; i < compare.length(); i++) {
            int matches = 0;

            for (int j = 1; j < strs.size(); j++) {
                // prefix can only be as long as shortest string
                if (i >= strs[j].length()) {
                    break;
                }

                if (strs[j][i] == compare[i]) {
                    matches++;
                }
            }

            if (matches == strs.size() - 1) {
                prefix += compare[i];
            }
            else {
                break;
            }
        }

        return prefix;
    }
};