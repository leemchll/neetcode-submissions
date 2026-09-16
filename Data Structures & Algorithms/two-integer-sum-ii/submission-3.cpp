class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Two pointers indices
        int left = 0;
        int right = numbers.size() - 1;

        // If current sum is bigger, move right inward
        // else current sum is smaller, move left inward
        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                return {left + 1, right + 1};
            }
            else if (sum > target) {
                right--;
            }
            else {
                left++;
            }
        }
    }
};
