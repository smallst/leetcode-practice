class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly = {1};
        int *times = new int [primes.size()];
        for (int i = 0;i < primes.size(); i++)
        {
            times[i] =0;
        }
        for(int k = 1;k < n; k++)
        {
            int min = INT_MAX;
            for(auto i = 0; i!= primes.size(); i++)
            {   
                int temp = (primes[i]) * ugly[times[i]];
                min = min < temp ? min : temp;
            }   
            ugly.push_back(min);
            for(auto i = 0; i!= primes.size(); i++)
            {   
                int temp = (primes[i]) * ugly[times[i]];
                if(temp == min )
                {
                    times[i] ++;
                }
            }   
        }
        return ugly[n-1];
    }
};
