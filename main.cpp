class Solution {
public:
    int hIndex(vector<int>& citations) {
        int low = 0, high = citations.size();
        int length = high;
        while(low < high )
        {
               int mid = (low + high) / 2;
            if(mid == 0)
            {
                return citations[0] == 0? 0 : 1;
            }
            nth_element(citations.begin(), citations.begin() + length -1 - mid, citations.end());
            int midValue = *(citations.begin() + length - mid -1);
            nth_element(citations.begin(), citations.begin() + length - mid, citations.end());
            int nextValue = *(citations.begin() + length - mid );
            if(midValue <= mid && nextValue >= mid)
            {
                low = mid;
                break;
            }
            else if(midValue > mid)
            {
                low = mid+1;
            }
            else if(nextValue < mid)
            {
                high = mid;
            }

        }
        return low;
    }
};
