class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:   
        # return list of all triplets
        triplets = []

        # sort nums into ascending order
        nums.sort()

        # i, j, k corresponds to the index of first, second, and third number
        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            
            # j is left pointer
            # k is right pointer
            j = i + 1
            k = len(nums) - 1

            while j < k:
                sum = nums[i] + nums[j] + nums[k]

                if sum < 0:
                    j += 1
                elif sum > 0:
                    k -= 1
                else:
                    triplets.append([nums[i], nums[j], nums[k]])
                    j += 1
                    k -= 1

                    while j < k and nums[j] == nums[j - 1]:
                        j += 1

                    while j < k and nums[k] == nums[k + 1]:
                        k -= 1

        return triplets

