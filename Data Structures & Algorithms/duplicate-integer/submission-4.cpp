class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> seen;

        for (int n : nums) {
            auto it = seen.find(n);

            if (it != seen.end())
                return true;

            seen.insert(n);
        }

        return false;
    }
};