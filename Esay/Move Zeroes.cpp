//https://leetcode.com/problems/move-zeroes/description/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    int lastNonZeroFoundAt = -1;
    int n = nums.size();

    for (int currentIndex = 0; currentIndex < n; ++currentIndex) {
        if (nums[currentIndex] != 0) {
            swap(nums[++lastNonZeroFoundAt], nums[currentIndex]);
        }
    }
  }
};
