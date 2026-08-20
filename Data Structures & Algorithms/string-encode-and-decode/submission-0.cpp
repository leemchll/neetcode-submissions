class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";

        for (string s : strs) {
            encoded_string += to_string(s.length()) + ":" + s;
        }

        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strs;

        int i = 0;

        while (i < s.length()) {
            
            // Determine length of string
            string length = "";

            while (s[i] != ':') {
                length += s[i];
                i++;
            }

            // Convert str to int
            int len = stoi(length);

            i++;

            string str = "";

            for (int j = 0; j < len; j++) {
                str += s[i + j];
            }

            decoded_strs.push_back(str);

            i += len;
        }

        return decoded_strs;
    }
};
