//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
class Solution {
    public int[] searchRange(int[] nums, int target) {
         int firstOccurence = searchBounds(nums, target, true);
        if(firstOccurence == -1)
            return new int[]{-1, -1};
        int lastOccurence = searchBounds(nums, target, false);
        return new int[]{firstOccurence, lastOccurence};
    }
    public int searchBounds(int nums[], int target, boolean isFirst)
    {
        int l = 0;
        int u = nums.length - 1;

        while(l <= u)
        {
            int mid = l + (u - l) / 2;

            if(nums[mid] == target)
            {
                if(isFirst)
                {
                    if(mid == l || nums[mid - 1] != target)
                        return mid;
                    else
                        u = mid - 1;
                }
                else
                {
                    if(mid == u || nums[mid + 1] != target)
                        return mid;
                    else
                        l = mid + 1;
                }
            }
            else if(target > nums[mid])
                l = mid + 1;
            else
                u = mid - 1;
        }

        return -1;
    }
}
