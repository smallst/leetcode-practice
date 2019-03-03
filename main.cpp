class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int l = s.length();
        
        vector<bool> dp(l+1, false);
        dp[0] = true;
        
        for(int i = 1; i<= l; i++)
        {
            for(int j = i-1; j >=0 ;j --)
            {
                if(dp[j])
                {
                    string t = s.substr(j, i-j);
                    if(find(wordDict.begin(), wordDict.end(), t) != wordDict.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[l];
    }
};
