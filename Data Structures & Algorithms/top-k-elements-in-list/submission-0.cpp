class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // first = unique number
        // second = frequency
        unordered_map<int, int> frequency;

        for (int n : nums) {
            frequency[n]++; // increase count of a number for every appearance
        }

        // Reorder the frequencies in descending
        priority_queue<pair<int, int>> ordered;

        // Swap position of count and number so that the priority queue orders our numbers by their frequencies
        for (auto& [number, count] : frequency) {
            ordered.push({count, number});
        }

        // Determine k frequencies
        vector<int> answer;

        for (int i = 0; i < k; i++) {
            answer.push_back(ordered.top().second);
            ordered.pop();
        }

        return answer;
    }
};
