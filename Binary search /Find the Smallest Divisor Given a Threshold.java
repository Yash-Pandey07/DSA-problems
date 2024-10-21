//https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
class Solution {
    public static int sumByD(int[] arr, int div) {
        int n = arr.length; //size of array
        //Find the summation of division values:
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += Math.ceil((double)(arr[i]) / (double)(div));
        }
        return sum;
    }

    public int smallestDivisor(int[] nums, int threshold) {
        int n = nums.length; //size of array.
        if(n > threshold) return -1;
        //Find the maximum element:
        int maxi = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            maxi = Math.max(maxi, nums[i]);
        }

        int low = 1, high = maxi;

        //Apply binary search:
        while (low <= high) {
            int mid = (low + high) / 2;
            if (sumByD(nums, mid) <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
}
