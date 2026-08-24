class Solution {
public:
    bool isAnagram(string s, string t) {
        // Cannot be anagrams if their lengths are different
        if (s.length() != t.length()) {
            return false;
        }

        // Use a vector to get the count of each letter in anagram
        vector<int> count(26, 0);

        for (int i = 0 ; i < s.length(); i++) {
            count[s[i] - 'a']++; // for every letter add to count
            count[t[i] - 'a']--; // for every matching letter cancel out
        }

        // If list the list comes out as all 0's,
        // that means letter count is exact same -> anagram
        for (int n : count) {
            if (n != 0) {
                return false;
            }
        }

        return true;
    }
};
