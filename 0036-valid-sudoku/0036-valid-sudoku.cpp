class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig){
        //horizontal
        for(int j=0; j<9 ;j++){
            if(board[row][j] == dig) return false;
        }

        //vertical
        for(int i =0;i<9;i++){
            if(board[i][col] == dig) return false;
        }

        // the 3*3 grid
        int startRow = (row/3)*3;
        int startCol = (col/3)*3;
        for( int i =startRow ; i<startRow+3 ; i++){
            for( int j= startCol ; j< startCol+3 ; j++){
                if(board[i][j] == dig) return false;
            }
        }
        return true;
    }


    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row = 0; row < 9; row++) {

            for(int col = 0; col < 9; col++) {

                if(board[row][col] == '.')
                    continue;

                char dig = board[row][col];

                // Remove current digit temporarily
                board[row][col] = '.';

                if(!isSafe(board, row, col, dig))
                    return false;

                // Restore digit
                board[row][col] = dig;
            }
        }

        return true;
    }
};