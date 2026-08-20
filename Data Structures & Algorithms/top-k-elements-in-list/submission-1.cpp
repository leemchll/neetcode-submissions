class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;

        for (int n : nums) {
            frequency[n]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);

        for (auto& [number, count] : frequency) {
            buckets[count].push_back(number);
        }

        vector<int> answer;

        for (int i = nums.size(); i > 0; i--) {
            for (int number : buckets[i]) {
                answer.push_back(number);

                if (answer.size() == k)
                    return answer;
            }
        }

        return answer;
    }
};