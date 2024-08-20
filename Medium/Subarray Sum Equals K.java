//https://leetcode.com/problems/subarray-sum-equals-k/description/
import java.util.*;
class Solution {
    public int subarraySum(int[] nums, int k) {

    int n = nums.length; // size of the given array.
    Map mpp = new HashMap();
    int preSum = 0, count = 0;
    mpp.put(0, 1); // Setting 0 in the map.

    for(int i=0;i<n;i++){
       // add current element to prefix Sum:
        preSum += nums[i];
        // Calculate x-k:
        int remove = preSum - k;

        // Add the number of subarrays to be removed:
        count += (int) mpp.getOrDefault(remove, 0);

        // Update the count of prefix sum
        // in the map.
        mpp.put(preSum, (int) mpp.getOrDefault(preSum, 0) + 1);
    }
    return count;
    }
}
