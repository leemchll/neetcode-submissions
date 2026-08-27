class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # removes duplicates
        unique = set(nums)

        # find the longest count of consecutive
        # O(n)
        longest = 0
        for n in unique:
            if n - 1 not in unique:
                start = n
                count = 1

                # starting at n, find its consecutive count
                while start + 1 in unique:
                    count += 1
                    start += 1

                longest = max(longest, count)

        return longest

            