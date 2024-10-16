//https://leetcode.com/problems/koko-eating-bananas/
class Solution {
    public static int findMax(int[] v) {
        int maxi = Integer.MIN_VALUE;
        int n = v.length;
        // Find the maximum:
        for (int i = 0; i < n; i++) {
            maxi = Math.max(maxi, v[i]);
        }
        return maxi;
    }

    public static long calculateTotalHours(int[] v, int hourly) {
        long totalH = 0;
        int n = v.length;
        // Find total hours:
        for (int i = 0; i < n; i++) {
            totalH += (v[i] + hourly - 1) / hourly; // This avoids using Math.ceil and ensures integer division
        }
        return totalH;
    }

    public int minEatingSpeed(int[] piles, int h) {
        int low = 1, high = findMax(piles);

        // Apply binary search:
        while (low <= high) {
            int mid = low + (high - low) / 2; // Avoid potential overflow
            long totalH = calculateTotalHours(piles, mid);
            if (totalH <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
}
