class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;

        for (int r = 0; r < 9; r++){
            for (int c = 0; c < 9; c++){
            char value = board[r][c];
                if (value == '.'){
                    continue;
                }
                string row_id = to_string(r) + 'r' + value;
                string col_id = to_string(c) + 'c' + value;
                string grid_id = to_string(r/3) + '_' +  to_string(c/3) + 'g' + value;

                if (seen.count(row_id) || seen.count(col_id) || seen.count(grid_id)){
                    return false;
                }

                seen.insert(row_id);
                seen.insert(col_id);
                seen.insert(grid_id);
            }
        }

        return true;
    }
};
