class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // O(n) without division
        int len = nums.size(); 

        // Determine the prefix product of each index
        vector<int> prefix(len, 1);

        for (int i = 1; i < len; i++) {
            if (i == 1)
                prefix[i] = nums[i - 1];
            else
                prefix[i] = nums[i - 1] * prefix[i - 1];
        }

        // Determine the suffix product of each index
        vector<int> suffix(len, 1);

        for (int j = len - 2; j >= 0; j--) {
            if (j == len - 2)
                suffix[j] = nums[j + 1];
            else
                suffix[j] = suffix[j + 1] * nums[j + 1];
        }

        // Multiply products together
        vector<int> answer(len, 1);

        for (int k = 0; k < len; k++) {
            answer[k] = prefix[k] * suffix[k];
        }
        
        return answer;
    }
};
