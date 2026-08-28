class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        seen = {}
        start = 0
        longest = 0

        for i in range(len(s)):
            # Check if dupe is in our substring
            if s[i] in seen and seen[s[i]] >= start:
                start = seen[s[i]] + 1

            # Update the most recent time we saw this char
            seen[s[i]] = i
            
            # Determine current length of our substring
            length = i - start + 1
            
            # Update our longest substring
            longest = max(longest, length)

        return longest
            
