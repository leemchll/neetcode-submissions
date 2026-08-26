class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> frequency;

        int maxLength = 0; 
        int maxFrequent = 0;
        int start = 0;

        for (int i = 0; i < s.length(); i++) {
            frequency[s[i]]++;

            maxFrequent = max(maxFrequent, frequency[s[i]]);

            while ((i - start + 1) - maxFrequent > k) {
                frequency[s[start]]--;
                start++;
            }

            maxLength = max(maxLength, i - start + 1);
        }

        return maxLength;
    }
};
