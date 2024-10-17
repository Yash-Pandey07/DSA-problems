//https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
class Solution {
    public int minDays(int[] bloomDay, int m, int k) {
        int n = bloomDay.length;
        long val = (long) m * k;
        if (val > n) return -1; // impossible case

        int minDay = Integer.MAX_VALUE;
        int maxDay = Integer.MIN_VALUE;

        // Find the minimum and maximum bloom days
        for (int day : bloomDay) {
            minDay = Math.min(minDay, day);
            maxDay = Math.max(maxDay, day);
        }

        // Binary search to find the minimum number of days
        int low = minDay, high = maxDay;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canMakeBouquets(bloomDay, mid, m, k)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
    
    private boolean canMakeBouquets(int[] bloomDay, int day, int m, int k) {
        int count = 0;
        int bouquets = 0;

        for (int bloom : bloomDay) {
            if (bloom <= day) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
        return bouquets >= m;
    }
}
