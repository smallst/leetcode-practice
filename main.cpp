class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int Y = 0, X = 0;
        if(matrix.size() > 0)
        {
            X = matrix[0].size();
            X --;
        }
        while(Y + 1 <= matrix.size() && X >= 0)
        {
            if( target == matrix[Y][X])
            {
                return true;
            }
            else if(target < matrix[Y][X])
            {
                X --;
            }
            else
            {
                Y ++;
            }
        }
        return false;
    }
};
