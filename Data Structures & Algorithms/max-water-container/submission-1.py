class Solution:
    def maxArea(self, heights: List[int]) -> int:
        units = 0

        left = 0
        right = len(heights) - 1

        while left < right:
            height = min(heights[left], heights[right])
            width = right - left
            units = max(units, height * width)

            if (heights[left] < heights[right]):
                left += 1
            else:
                right -= 1
            
        return units