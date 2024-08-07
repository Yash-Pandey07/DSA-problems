//https://leetcode.com/problems/next-permutation/description/
import java.util.Arrays;

class Solution {
    public void nextPermutation(int[] nums) {
        // Initialize index to -1, which will be used to store the position
        // where the next greater permutation needs to be found
        int index = -1;
        int n = nums.length;

        // Find the first index from the end where the current element is less than the next element
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        // If no such index is found, reverse the entire array to get the smallest permutation
        if (index == -1) {
            reverse(nums, 0, n - 1);
            return;
        }

        // Find the first element from the end that is greater than the element at the found index
        for (int i = n - 1; i > index; i--) {
            if (nums[i] > nums[index]) {
                swap(nums, i, index);
                break;
            }
        }

        // Reverse the elements after the found index to get the next permutation
        reverse(nums, index + 1, n - 1);
    }

    // Helper method to reverse elements in the array
    private void reverse(int[] nums, int start, int end) {
        while (start < end) {
            swap(nums, start, end);
            start++;
            end--;
        }
    }

    // Helper method to swap elements in the array
    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
