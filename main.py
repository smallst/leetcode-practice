class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        pair = []
        mp = {}
        i = 0
        for n in nums:
            mp[n] = i
            pair.append(target - n)
            i += 1
        i = 0
        for n in pair:
            if n in mp and i != mp[n]:
                return [i, mp[n]]
            i += 1
