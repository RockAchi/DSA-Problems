class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //Solving this using Inplace Algorithm 
        //Travarse the Array and use First row and cloumn as a memeory which rows and columns needs to be set 0
        //like if matrix[i][j] = 0, then we have to set zero to i row and j cloumn in matrix
        //so for that we will store matrix[i][0]=0 and matrix[0][j]=0

        //Special Handling is require for first row and first column because, lets say first row 
        //contains a zero matrix[0][i], then we have to set zero i'th column and 0'th row, 
        //but as per our algorithm we will store matrix[0][0] = 0 and matrix[0][i]
        //Now if you see matrix[0][0] means we have to set both first cloumn and first row to 0, which is wrong
        //Similarly for first column if contains zero matrix[i][0]=0, then matrix[i][0]=0 and matrix[0][0]=0(this is wrong) 

        int rowSize = matrix.size();
        int columnSize = matrix[0].size();
        int setFirstRowZeroes = 0, setFirstColumnZeroes = 0;
        //Handling Special Case1: Check first Row contains any zero,
        //so that we remember that we have set the first row to zeros
        for (int j = 0; j < columnSize; j++) {
            if (matrix[0][j] == 0)
                setFirstRowZeroes = 1;
        }
        for (int i = 0; i < rowSize; i++) {
            if (matrix[i][0] == 0)
                setFirstColumnZeroes = 1;
        }

        if (rowSize > 1 && columnSize > 1) {
            for (int i = 1; i < rowSize; i++) {
                for (int j = 1; j < columnSize; j++) {
                    if (matrix[i][j] == 0) {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
            for (int i = 1; i < columnSize; i++) {
                if (matrix[0][i] == 0) {
                    int j = 0;
                    while (j != rowSize) {
                        matrix[j][i] = 0;
                        j++;
                    }
                }
            }

            for (int i = 1; i < rowSize; i++) {
                if (matrix[i][0] == 0) {
                    int j = 0;
                    while (j != columnSize) {
                        matrix[i][j] = 0;
                        j++;
                    }
                }
            }
        }

        if (setFirstRowZeroes) {
            int j = 0;
            while (j != columnSize)
                matrix[0][j++] = 0;
        }
        if (setFirstColumnZeroes) {
            int i = 0;
            while (i != rowSize)
                matrix[i++][0] = 0;
        }
    }
};
