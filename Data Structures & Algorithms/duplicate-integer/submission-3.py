class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        seen = set() # use set b/c lookup is O(1)

        for n in nums:
            if n in seen:
                return True
            
            seen.add(n)

        return False