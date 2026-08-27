class Solution:

    def encode(self, strs: List[str]) -> str:
        # a string
        encoded_string = ""

        for s in strs:
            encoded_string += str(len(s)) + "#" + s

        return encoded_string

    def decode(self, s: str) -> List[str]:
        # a list
        decoded_strings = []

        i = 0
        
        # loop through encoded string
        while i < len(s):
            j = i

            # find the range of the count
            while s[j] != "#":
                j += 1

            # cast the string number into an int
            length = int(s[i:j])

            # move j past the hashtag
            j += 1

            # add string into list given the range of the string
            decoded_strings.append(s[j:j + length])

            i = j + length

        return decoded_strings
