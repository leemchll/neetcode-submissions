class Solution {
    public boolean isAnagram(String s, String t) {
        // Base Case
        if (s.length() != t.length()) {
            return false;
        }

        // Initialize
        int[] count = new int[26]; // we know there is an exact count so no need for complex set

        for (int i = 0; i < s.length(); i++) {
            count[s.charAt(i) - 'a']++;
            count[t.charAt(i) - 'a']--;
        }

        for (int n : count) {
            if (n != 0) {
                return false;
            }
        }

        return true;
    }
}
