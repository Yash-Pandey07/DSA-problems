//https://leetcode.com/problems/binary-search/description/
class Solution {
    ////Recursive Approach

    public static int binarySearch(int[] nums, int low, int high, int target) {
        if (low > high) return -1; //Base case.

        // Perform the steps:
        int mid = (low + high) / 2;
        if (nums[mid] == target) return mid;
        else if (target > nums[mid])
            return binarySearch(nums, mid + 1, high, target);
        return binarySearch(nums, low, mid - 1, target);
    }

    public int search(int[] nums, int target) {
        return binarySearch(nums, 0, nums.length - 1, target);

    ////Iterative Implementation
    // int n = nums.length; //size of the array
    // int low = 0, high = n - 1;

    // // Perform the steps:
    // while (low <= high) {
    //     int mid = (low + high) / 2;
    //     if (nums[mid] == target) return mid;
    //     else if (target > nums[mid]) low = mid + 1;
    //     else high = mid - 1;
    // }
    // return -1;
    }
}
