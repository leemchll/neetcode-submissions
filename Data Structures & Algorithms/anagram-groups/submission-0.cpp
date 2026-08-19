class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // key = alphabet count of an anagram 
        // values = anagrams of the same alphabet count
        std::map<vector<int>, vector<std::string>> anagramMap = {};
        
        for (std::string word: strs) {
            // Initialize alphabet count to 0
            vector<int> anagram(26, 0);

            // For each word, determine unique alphabet count
            for (char l: word) {
                anagram[l - 'a']++;
            }
            
            // Inserts key based on existence
            anagramMap[anagram].push_back(word);
        }

        // Create sublists of anagrams
        vector<vector<std::string>> sublists;

        for (auto pair : anagramMap) {
            sublists.push_back(pair.second);
        }

        return sublists;

    }
};
