class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if len(s) < len(t):
            return ""

        # Find the frequency of each letter
        frequency = {}

        for c in t:
            frequency[c] = frequency.get(c, 0) + 1
            
        window = {}
        have = 0
        need = len(frequency)

        start = 0
        result_start = 0 
        shortest = float("inf")

        for end in range(len(s)):
            char = s[end]
            window[char] = window.get(char, 0) + 1

            if char in frequency and window[char] == frequency[char]:
                have += 1

            # Check for shorter substrings after first match was found
            while have == need:
                current_length = end - start + 1
                
                if current_length < shortest:
                    shortest = current_length
                    result_start = start

                left_char = s[start]
                window[left_char] -= 1

                if left_char in frequency and window[left_char] < frequency[left_char]:
                   have -= 1

                start += 1

        if shortest == float("inf"):
                return ""

        return s[result_start:result_start + shortest]