class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int l = nums.size();
        
        vector<string> res;
        if(l == 0)
            return res;
        int start = 0;
        for(int i = 0; i<l-1; i++)
        {
            if(nums[i] +1 < nums[i+1])    
            {
                if(i > start )
                res.push_back(to_string(nums[start]) + "->" + to_string(nums[i]));    
                else
                res.push_back(to_string(nums[start]));    
                
                start = i + 1;
            }
        }
        if(start != l -1)
                res.push_back(to_string(nums[start]) + "->" + to_string(nums[l-1]));    
                else
                res.push_back(to_string(nums[start]));    
    
            return res;
    }
   
};
