class Solution {
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        unordered_set<int> seen = {};

        for (int n : nums)
        {
            auto iter = seen.find(n);

            if (iter != seen.end())
                return true;
        
            seen.insert(n);
        }

        return false;

    }
};