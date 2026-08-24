class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        unique = []

        for n in nums:
            if not n in unique:
                unique.append(n)
            else:
                return True
        
        return False
        