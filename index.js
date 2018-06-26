var twoSum = function(nums, target) {
    mp = {};
    for(i = 0; i< nums.length; i++)
    {
        mp[nums[i]] = i;         
    }
    for(i = 0; i < nums.length;i ++)
        {
            temp = target - nums[i];
           if(temp in mp && mp[temp] != i)
               {
                   return [i, mp[temp]];
               }
        }
};