class Solution {
public:
    bool checkValid(int a,int b,int X,int Y)
    {
        if(a < 0 || a >= X  || b < 0 || b >=Y)
            return true;
        return false;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int X = board.size();
        int Y = (*board.begin()).size();
        for(auto x = 0; x != X ; x++)
        {
            for(auto y = 0; y != Y; y++)
            {
                int count = 0;
                for(int i = -1; i< 2; i++)
                {
                    for(int j = -1; j< 2; j++)
                    {
                        if((i ==0 && j == 0) || checkValid(x+i, y+j, X, Y))
                        {
                            continue;
                        }
                        count += (board[x+i][y+j]&1);  
                    }
                }
                if(count == 3)
                {
                    board[x][y] |= (1<<1);
                }
                else if(count < 2 || count > 3)
                {
                    board[x][y] &= 1;
                }
                else
                {
                    board[x][y] |= (board[x][y] << 1);
                }
            }
        }
        for(auto x = 0; x != X ; x++)
        {
            for(auto y = 0; y != Y; y++)
            {
                board[x][y] >>= 1;
            }
        }
    }
};
