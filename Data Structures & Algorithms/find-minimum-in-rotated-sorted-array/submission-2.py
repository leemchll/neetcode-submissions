class Solution:
    def findMin(self, nums: List[int]) -> int:
        answer = 1000

        for n in nums:
            answer = min(answer, n)

        return answer