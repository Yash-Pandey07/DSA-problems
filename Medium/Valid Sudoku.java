//https://leetcode.com/problems/valid-sudoku/description/

class Solution {
    public boolean isValidSudoku(char[][] board) {
        int N= board.length;
        
//use hashset to record the status

    HashSet<Character>[] rows = new HashSet[N];
    HashSet<Character>[] cols = new HashSet[N];
    HashSet<Character>[] boxes = new HashSet[N];

    for(int r=0; r<N; r++){
        rows[r] = new HashSet<Character>();
        cols[r] = new HashSet<Character>();
        boxes[r] = new HashSet<Character>();
    }

    for(int r = 0;r<N; r++){
        for( int c = 0; c< N; c++){
            char val = board[r][c];

            /// check the position value is filled with blank(.) or any value

            //if filled with (.)
            if(val == '.') continue ;

            if(rows[r].contains(val) || cols[c].contains(val)){
                return false;
            }
            rows[r].add(val);
            cols[c].add(val);

            int idx = (r/3) * 3 + c/3 ;
            if(boxes[idx].contains(val)){
                return false;
            }
            boxes[idx].add(val);

        }
    }

    return true;
    }
}
