class Solution {
public:
    int kth(vector<int>& nums1, vector<int>& nums2, int as, int ae, int bs, int be, int k)
        {
            int al = ae - as;
            int bl = be - bs;
            if(al <= 0)
            {
                return nums2[bs + k - 1];
            }
            if(bl <= 0)
            {
                return nums1[as + k - 1];
            }
            if(k == 1)
            {
                return nums1[as] < nums2[bs] ? nums1[as] : nums2[bs];
            }
            int asplit = k * al / (al + bl);
            if(asplit == 0) asplit = 1;
            int bsplit = k - asplit;
            if(nums1[as + asplit-1] <= nums2[bs + bsplit-1])
            {
                return kth(nums1, nums2, as + asplit, ae, bs, bs + bsplit, k-asplit);
            }
            else
            {
                return kth(nums1, nums2, as, as + asplit, bs + bsplit, be, k-bsplit );
            }
        }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int la = nums1.size();
        int lb = nums2.size();
        if((la + lb)% 2 == 0)
        {
            int k = (la + lb)/2;
            // cout<<kth(nums1, nums2, 0, la, 0, lb, k)<<endl;
            // cout<<kth(nums1, nums2, 0, la, 0, lb, k+1)<<endl<<endl;;
            return (kth(nums1, nums2, 0, la, 0, lb, k) + kth(nums1, nums2, 0, la, 0, lb, k+1))/2.0;
        }
        else
        {
            int k = (la + lb) / 2 + 1;
            // cout<<kth(nums1, nums2, 0, la, 0, lb, k)<<endl<<endl;;;
            return kth(nums1, nums2, 0, la, 0, lb, k);
        }
    }

};
;