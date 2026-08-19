class Solution {
public:
    bool isAnagram(string s, string t) {
        // Base Case: different lengths
        if (s.length() != t.length())
            return false;

        vector<int> alphaCount(26, 0);

        for (int i = 0; i < s.length(); i++) {
            alphaCount[s[i] - 'a']++;
            alphaCount[t[i] - 'a']--;
        }

        for (int a : alphaCount) {
            if (a != 0)
                return false;
        }

        return true;
    }
};
