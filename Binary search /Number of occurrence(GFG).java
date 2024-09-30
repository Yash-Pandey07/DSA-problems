//https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1
class Solution {
    public int firstOccurrence(int[] arr, int n, int k) {
        int low = 0, high = n - 1;
        int first = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == k) {
                first = mid;
                high = mid - 1; // Move to the left half
            } else if (arr[mid] < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return first;
    }

    public int lastOccurrence(int[] arr, int n, int k) {
        int low = 0, high = n - 1;
        int last = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == k) {
                last = mid;
                low = mid + 1; // Move to the right half
            } else if (arr[mid] < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return last;
    }

    public int count(int[] arr, int n, int x) {
        int first = firstOccurrence(arr, n, x);
        if (first == -1) return 0; // x is not present in the array
        int last = lastOccurrence(arr, n, x);
        return (last - first + 1);
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr = {1, 1, 1, 2, 2, 3, 3};
        int n = arr.length;
        int x = 3;
        System.out.println("Total occurrences of " + x + " is " + sol.count(arr, n, x));
    }
}
