class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numbers(nums.begin(), nums.end());

        int longest = 0; // max consecutive

        for (int n : numbers) {
            if (numbers.find(n - 1) == numbers.end()) {
                int current = n; // index
                int count = 1; // current max consecutive

                while (numbers.find(current + 1) != numbers.end()) {
                    current++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};
