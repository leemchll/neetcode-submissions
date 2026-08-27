class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # dictionary
        # key = a number
        # value = number's frequency
        frequency = {}

        # if n doesn't exist return 0 inst of error
        # else add 1 to n's count
        for n in nums:
            frequency[n] = frequency.get(n, 0) + 1

        # Initialize empty lists
        buckets = [[] for _ in range(len(nums) + 1)]

        # list of lists
        # items() = (key, value)
        # (number, count)
        for number, count in frequency.items():
            buckets[count].append(number)

        # Fill in list
        answer = []

        # range(start index, stop index, step value aka decrement by 1)
        for count in range(len(buckets) - 1, 0, -1):
            for number in buckets[count]:
                answer.append(number)

                if len(answer) == k:
                    return answer