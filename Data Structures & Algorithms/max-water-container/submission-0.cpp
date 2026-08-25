class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int maxUnits = 0;

        while (left < right) {
            int currUnits = min(heights[left], heights[right]) *
                            (right - left);

            maxUnits = max(maxUnits, currUnits);

            if (heights[left] < heights[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return maxUnits;
    }
};