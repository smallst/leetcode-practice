class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int l = nums.size(), i;
        for(i = l - 1; i > 0; i--)
        {
            if(nums[i] > nums[i-1])
            {
                break;
            }
        }
        if(i==0)
        {
            reverse(nums, 0, l-1);
            return;
        }
        i--;
        for(int j = l-1; j>i;j--)
        {
            if(nums[i] < nums[j])
            {
                swap(nums, i, j);
                reverse(nums, i+1, l-1);
                return;
            }
        }
    }
    void swap(vector<int> & nums, int a, int b)
    {
        if(a >= b)
            return;
        nums[a] = nums[a] + nums[b];
        nums[b] = nums[a] - nums[b];
        nums[a] = nums[a] - nums[b];
    }
    void reverse(vector<int> & nums, int s, int e)
    {
        if(s >= e)
            return;
        for(int i =s; i <= (s+e)/2; i++)
        {
            swap(nums, i, s+e-i);
        }
    }
};
