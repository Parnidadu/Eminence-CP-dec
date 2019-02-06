bool isrowsafe(int board[][9], int row, int num) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num)
                return false;
        }
        return true;

    }

    bool iscolsafe(int board[][9], int col, int num) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == num)
                return false;
        }
        return true;

    }

    bool isboxsafe(int board[][9], int row, int col, int num) {
        int rowstart = row - row % 3;
        int colstart = col - col % 3;
        for (int i = rowstart; i < rowstart + 3; i++) {
            for (int j = colstart; j < colstart + 3; j++) {
                if (board[i][j] == num) {
                    return false;
                }
            }
        }
        return true;

}
bool canplacenum(int board[][9], int row, int col, int num) {
        if (!isrowsafe(board, row, num)) {
            return false;
        }
        if (!iscolsafe(board, col, num)) {
            return false;
        }
        if (!isboxsafe(board, row, col, num)) {
            return false;
        }
        return true;

    }
bool sudokuSolver(int board[][9]){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Don't print output and return output as specified in the question
  */
	int row = -1;
        int col = -1;
        bool isempty = false;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == 0) {
                    isempty = true;
                    row = i;
                    col = j;
                    break;
                }
            }
            if (isempty) {
                break;
            }
        }
        if (!isempty) {
            return true;
        }

        for (int num = 1; num <= 9; num++) {
            if (canplacenum(board, row, col, num)) {
                board[row][col] = num;
                if (sudokuSolver(board)) {
                    return true;
                } else {
                    board[row][col] = 0;
                }
            }

        }
        return false;

    }
