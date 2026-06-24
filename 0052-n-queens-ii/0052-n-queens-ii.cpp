class Solution {
public:
    bool isSafe( vector<string> & board, int row, int col, int n){
        //horizontal
        for(int i = 0; i< n; i++){
            if(board[row][i] == 'Q') return false;
        }

        //vertical
        for(int i =0 ; i<n ;i++){
            if(board[i][col]== 'Q') return false;
        }

        //left diagonal
        for( int i = row, j = col ; i>=0 && j>=0 ; i--,j--){
            if(board[i][j]== 'Q') return false;
        }

        //right diagonal
        for(int i = row, j = col ; i>=0 && j<n ; i--,j++){
            if(board[i][j]== 'Q') return false;

        }
        return true;
    }
    void helper( vector<string>& board, int row, int n, int& count){
        if(row == n){
            count++;
            return;
        }

        for(int j=0; j< n ;j++){
            if(isSafe(board, row, j, n)){
                board[row][j] = 'Q';
                helper(board,row+1,n,count);
                board[row][j] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        int count=0;
        helper( board, 0, n, count);
        return count;

    }
};