class Solution {
public:

int Y, X;
    int numIslands(vector<vector<char>>& grid) {
        Y = grid.size();
        if(Y == 0)
            return 0;
        X = grid[0].size();
        if(X == 0)
            return 0;
        int start =0;
        for(int i =0;i < Y;i++)
        {
            for(int j = 0; j < X; j++)
            {
                if(grid[i][j] == '1')
                {
                    deepSearch(grid, i, j);
                    start ++;
                }
            }
        }
        return start ;
    }
    bool valid(int i, int j)
    {
        if(i < 0  || j < 0 || i >= Y || j >= X)
            return false;
        return true;
    }
    void deepSearch(vector<vector<char>>& grid,  int x, int y)
    {
         if(!valid(x,y))
           return;
         if(grid[x][y] != '1')
         return;
        grid[x][y] = '$';
        deepSearch(grid,  x+1, y);
        deepSearch(grid,  x, y-1);
        deepSearch(grid,  x, y+1);
        deepSearch(grid,  x-1, y);
    }
};
