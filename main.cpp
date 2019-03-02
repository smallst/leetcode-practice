class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2)
        {
            return 0;
        }
        int * buy = new int [n];
        int * sell = new int [n];
        buy[0] = -prices[0];
        sell[0] = 0;
        buy[1] = prices[0] > prices[1] ? -prices[1] : -prices[0];
        sell[1] = buy[0] + prices[1] > 0 ?buy[0] + prices[1] : 0;
        for(int i =2; i< n; i++)
        {
            buy[i] = buy[i-1] > sell[i-2] - prices[i] ? buy[i-1] : sell[i-2] -prices[i];
            sell[i] = buy[i-1] + prices[i] > sell[i-1] ? buy[i-1] + prices[i] : sell[i-1];
        }
        return sell[n-1];
    }
};
