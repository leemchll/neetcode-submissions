class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = {}

        for str in strs:
            counts = [0] * 26

            for s in str:
                counts[ord(s) - ord("a")] += 1
            
            key = ""

            for c in counts:
                key += f"#{c}"

            if key not in anagrams:
                anagrams[key] = []

            anagrams[key].append(str)

        return list(anagrams.values())

                