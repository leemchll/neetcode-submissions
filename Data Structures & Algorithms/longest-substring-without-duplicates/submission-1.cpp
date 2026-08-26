class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // char first = a letter
        // int second = the index of the most recent appearance of letter
        unordered_map<char, int> lastSeen;
        int start = 0;
        int longest = 0;

        for (int i = 0; i < s.length(); i++) {
            char curr = s[i]; // current letter

            // if we have seen this letter before and it is in our current
            // substring, move the start to be the next letter after its
            // last occurence
            if (lastSeen.count(curr) && lastSeen[curr] >= start) {
                start = lastSeen[curr] + 1;
            }

            // update the most recent occurence of current letter
            lastSeen[curr] = i;

            int currentLen = i - start + 1;
            longest = max(currentLen, longest);
        }

        return longest;
    }
};
