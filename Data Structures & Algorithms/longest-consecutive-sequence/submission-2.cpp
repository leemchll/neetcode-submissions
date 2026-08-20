class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Put nums in a set to put numbers in ascending order and remove duplicates
        set<int> ascend(nums.begin(), nums.end());

        if (ascend.empty())
            return 0;

        int count = 1; // current consecutive count
        int longest = 1; // longest consecutive count
        auto iter = ascend.begin();
        auto nextIter = next(iter);

        while (nextIter != ascend.end()) {
            if (*nextIter == *iter + 1) {
                count++;
                longest = max(longest, count);
            }
            else {
                count = 1;
            }

            iter++;
            nextIter++;
        }

        return longest;
    }
};
