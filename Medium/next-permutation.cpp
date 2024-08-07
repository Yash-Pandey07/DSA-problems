//https://leetcode.com/problems/next-permutation/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
     int n = nums.size(); // Size of the given array
        int i = n - 2; // Start from the second last element

        // Find the first element that is not in a non-increasing sequence from the end
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }

        if (i >= 0) { // If such an element is found
            // Find the smallest element greater than nums[i] to the right of it
            for (int j = n - 1; j > i; --j) {
                if (nums[j] > nums[i]) {
                    std::swap(nums[i], nums[j]); // Swap them
                    break;
                }
            }
        }

        // Reverse the sequence from nums[i + 1] to the end of the array
        // This is to get the smallest possible permutation after i
        std::reverse(nums.begin() + i + 1, nums.end());
    }
};
