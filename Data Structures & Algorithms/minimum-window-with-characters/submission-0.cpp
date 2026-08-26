class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> frequencyT;

        for (char letter : t) {
            frequencyT[letter]++;
        }

        unordered_map<char, int> frequencyWindow;

        int start = 0;
        int matched = 0;
        int required = frequencyT.size();

        int shortestStart = 0;
        int shortestLength = INT_MAX;

        for (int end = 0; end < s.length(); end++) {
            char current = s[end];
            frequencyWindow[current]++;

            // This character now has the required frequency
            if (frequencyT.count(current) &&
                frequencyWindow[current] == frequencyT[current]) {
                matched++;
            }

            // The window currently contains everything from t
            while (matched == required) {
                int currentLength = end - start + 1;

                if (currentLength < shortestLength) {
                    shortestLength = currentLength;
                    shortestStart = start;
                }

                char removed = s[start];

                // Removing this character makes its frequency insufficient
                if (frequencyT.count(removed) &&
                    frequencyWindow[removed] == frequencyT[removed]) {
                    matched--;
                }

                frequencyWindow[removed]--;
                start++;
            }
        }

        if (shortestLength == INT_MAX) {
            return "";
        }

        return s.substr(shortestStart, shortestLength);
    }
};