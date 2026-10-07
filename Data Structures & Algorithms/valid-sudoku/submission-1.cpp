class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // unordered_set<string> seen;

        // for (int r = 0; r < 9; r++){
        //     for (int c = 0; c < 9; c++){
        //     char value = board[r][c];
        //         if (value == '.'){
        //             continue;
        //         }
        //         string row_id = to_string(r) + 'r' + value;
        //         string col_id = to_string(c) + 'c' + value;
        //         string grid_id = to_string(r/3) + '_' +  to_string(c/3) + 'g' + value;

        //         if (seen.count(row_id) || seen.count(col_id) || seen.count(grid_id)){
        //             return false;
        //         }

        //         seen.insert(row_id);
        //         seen.insert(col_id);
        //         seen.insert(grid_id);
        //     }
        // }

        // return true;

        int rows[9] = {0};
        int cols[9] = {0};
        int squares[9] = {0};

        for (int r = 0; r < 9; r++){
            for (int c = 0; c < 9; c++){
                char val = board[r][c];
                if (val == '.'){
                    continue;
                }
                int bit = int(val) - 1;

                if ((rows[r] & (1 << bit)) || (cols[c] & (1 << bit)) || (squares[(r/3)*3 + c/3] & (1 << bit))) return false;

                rows[r] |= (1 << bit);
                cols[c] |= (1 << bit);
                squares[(r/3)*3 + c/3] |= (1 << bit);
            }
        }

        return true; 
    }
};
