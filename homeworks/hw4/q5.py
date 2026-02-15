class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        i,mr,last,jumps=0,0,0,0
        while(last < n-1):
            mr = max(mr,i + nums[i])
            if i == last: 
                last = mr
                jumps += 1
            i += 1
        return jumps
