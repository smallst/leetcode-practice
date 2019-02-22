class Solution {
public:
    int * res = NULL;
    int numSquares(int n) {
        int s = sqrt(n);
        if(s*s == n) return 1;
        if(res == NULL){
            res = new int [n + 1];
            for(int i =0 ;i <= n;  i++)
            {
                res[i] = -1;
            }
        }
        if(res[n]  != -1)
        {
            return res[n];
        }
        int min = INT_MAX;
 
        for (int i =s; i > 0; --i) {
            int a = 1 + numSquares(n - i*i);
            min = a < min ? a : min;
        }
        res[n] = min;
        return min;
    }
};
;