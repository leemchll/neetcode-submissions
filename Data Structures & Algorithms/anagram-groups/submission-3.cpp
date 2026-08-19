class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;

        for (const string& word : strs) {
            int count[26] = {};

            for (char l : word) {
                count[l - 'a']++;
            }

            string key = "";

            for (int i = 0; i < 26; i++) {
                key += "#" + to_string(count[i]);
            }

            anagramMap[key].push_back(word);
        }

        vector<vector<string>> sublists;

        for (auto& [key, group] : anagramMap) {
            sublists.push_back(group);
        }

        return sublists;
    }
};