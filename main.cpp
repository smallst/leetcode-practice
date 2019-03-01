class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss = 1;
        int patch = 0;
        auto i = nums.begin();
        while(miss <= n)
        {
                if(i >= nums.end() || miss < (*i))
                {
                    patch ++;
                    miss += miss;
                }
                else
                {
                    miss += (*i);
                        i++;
                }
            
        }
        return patch;
    }
};
