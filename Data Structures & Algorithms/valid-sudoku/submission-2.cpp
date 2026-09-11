class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char value = board[r][c];

                if (value == '.')
                    continue;

                int box = (r / 3) * 3 + (c / 3);

                if (rows[r].contains(value) ||
                    cols[c].contains(value) ||
                    boxes[box].contains(value)) {
                    return false;
                }

                rows[r].insert(value);
                cols[c].insert(value);
                boxes[box].insert(value);
            }
        }

        return true;
    }
};