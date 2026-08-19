class Solution 
{
public:
    bool isAnagram(string s, string t) 
    {
        // Base Case: They cannot be anagrams if they're different lengths.
        if (s.length() != t.length())
            return false;
        
        // Sort both strings alphabetically
        vector<int> alphaS = {};
        vector<int> alphaT = {};
        
        for (int i = 0; i < s.length(); i++)
        {
            auto positionS = lower_bound(alphaS.begin(), alphaS.end(), s[i]);
            auto positionT = lower_bound(alphaT.begin(), alphaT.end(), t[i]);

            alphaS.insert(positionS, s[i]);
            alphaT.insert(positionT, t[i]);
        }

        // Compare ordered strings
        if (alphaS == alphaT)
            return true;

        return false;
    }
};
