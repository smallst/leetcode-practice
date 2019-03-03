class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size();
        while(left + 1 < right)
        {
            int mid = (left + right) / 2;
            if(mid == 0 && nums[mid] > nums[mid+1])
            {
                return 0;
            }
            if(mid + 1 == nums.size())
                if(nums[mid] > nums[mid-1])
                return mid;
            else{
                right = mid;
                continue;
            }
            if(nums[mid] > nums[mid-1])
            {
                if( nums[mid] > nums[mid+1])
                return mid;
                else
                {
                    left = mid;
                }
            }
            else{
                right = mid;
            }
        }
        return left;
    }
};
