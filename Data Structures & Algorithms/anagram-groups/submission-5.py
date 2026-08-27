class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        keys = {}

        # look at each string
        for s in strs:
            # get count of each letter in a string
            count = [0] * 26

            for i in range(len(s)):
                count[ord(s[i]) - ord("a")] += 1

            # turn the letter count into a key
            key = tuple(count)

            if key not in keys:
                keys[key] = []
            
            # add key to key list
            keys[key].append(s)

        return list(keys.values())


            