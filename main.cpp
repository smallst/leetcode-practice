class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> pair, ret;
        map<int, int> mp;
        int i = 0;
        for(auto it = nums.begin(); it != nums.end(); it++, i++)
        {
            mp[*it] = i;
            pair.push_back(target-(*it));   
        }
        i = 0;
        for(auto it = pair.begin(); it != pair.end(); it++, i++)
        {
            if(mp.find(*it) != mp.end() && i != mp[*it])
            {
                ret.push_back(i);
                ret.push_back(mp[*it]);
                break;
            }
        }
        return ret;
    }
};