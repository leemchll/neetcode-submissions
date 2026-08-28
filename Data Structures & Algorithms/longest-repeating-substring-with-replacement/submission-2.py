class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        frequency = {} 

        frequent = 0 
        start = 0 
        longest = 0

        for i in range(len(s)):
            # add to frequency of letter
            frequency[s[i]] = frequency.get(s[i], 0) + 1

            # update most frequent letter
            frequent = max(frequent, frequency[s[i]])
            
            # compare our current possible substring length with current longest
            while i - start + 1 - frequent > k:
                frequency[s[start]] -= 1
                start += 1

            length = i - start + 1
            longest = max(longest, length)

        return longest