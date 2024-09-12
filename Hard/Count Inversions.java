//https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
// User function Template for Java
class Solution {
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
public static long merge(long[] arr, long low, long mid, long high) {
        long count = 0;
        List<Long> temp = new ArrayList<>();
        long left = low;
        long right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr[(int)left] <= arr[(int)right]) {
                temp.add(arr[(int)left]);
                left++;
            } else {
                temp.add(arr[(int)right]);
                count += (mid - left + 1);
                right++;
            }
        }

        while (left <= mid) {
            temp.add(arr[(int)left]);
            left++;
        }

        while (right <= high) {
            temp.add(arr[(int)right]);
            right++;
        }

        for (int i = (int)low; i <= high; i++) {
            arr[i] = temp.get(i - (int)low);
        }

        return count;
    }

    public static long mergeSort(long[] arr, long low, long high) {
        if (low >= high) return 0;

        long mid = (high + low) / 2;
        long count = 0;

        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid + 1, high);
        count += merge(arr, low, mid, high);

        return count;
    }
    static long inversionCount(long arr[]) {
        // Your Code Here
        return mergeSort(arr, 0, arr.length - 1);
        
    }
}
