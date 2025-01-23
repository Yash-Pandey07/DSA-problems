class Solution {
    public int kthElement(int a[], int b[], int k) {
        int m = a.length, n = b.length;
        if (m > n) return kthElement(b, a, k);

        int low = Math.max(0, k - n), high = Math.min(k, m);
        while (low <= high) {
            int mid1 = (low + high) >> 1;
            int mid2 = k - mid1;
            int l1 = (mid1 == 0) ? Integer.MIN_VALUE : a[mid1 - 1];
            int l2 = (mid2 == 0) ? Integer.MIN_VALUE : b[mid2 - 1];
            int r1 = (mid1 == m) ? Integer.MAX_VALUE : a[mid1];
            int r2 = (mid2 == n) ? Integer.MAX_VALUE : b[mid2];

            if (l1 <= r2 && l2 <= r1) {
                return Math.max(l1, l2);
            } else if (l1 > r2) {
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
        }
        return 0; // this line will never be reached if input is valid
    }
}
