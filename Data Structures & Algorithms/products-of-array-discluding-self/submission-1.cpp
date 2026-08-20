class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();

        vector<int> answer(len, 1);

        for (int i = 1; i < len; i++) {
            answer[i] = answer[i - 1] * nums[i - 1];
        }

        int suffix = 1;

        for (int i = len - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return answer;
    }
};