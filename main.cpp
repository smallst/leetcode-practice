class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int y = matrix.size();
        if(y == 0)
            return res;
        int x = matrix[0].size();
        if(x == 0)
            return res;
        
        int w = x, h = y, sw = 0, sh = 0;
        while(true)
        {
            for(int i = sw; i < w;i ++)
            {
                res.push_back(matrix[sh][i]);
            }
            if(sw >= w)
                break;
            for(int i = sh+1; i < h; i++)
            {
                res.push_back(matrix[i][w-1]);
            }
            if(sh +1 >=h )
            break;

            for(int i = w-2; i >=sw; i--)
            {
                res.push_back(matrix[h-1][i]);
            }
            if(sw + 2 > w)
            {
                break;
            }
            for(int i = h-2; i>sh; i--)
            {
                res.push_back(matrix[i][sw]);
            }
            sh ++;
            sw ++;
            h--;
            w --;
            if(sh >=h)
                break;
        }
        return res;
    }
};
