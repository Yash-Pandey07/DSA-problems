//https://leetcode.com/problems/reverse-pairs/description/
//Count Reverse Pairs
class Solution {
    // Function to merge two halves of the array
    private static void merge(int[] arr, int low, int mid, int high) {
        int[] temp = new int[high - low + 1]; // temporary array
        int left = low;      // starting index of left half of arr
        int right = mid + 1;   // starting index of right half of arr
        int k = 0;

        // storing elements in the temporary array in a sorted manner
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp[k++] = arr[left++];
            } else {
                temp[k++] = arr[right++];
            }
        }

        // if elements on the left half are still left
        while (left <= mid) {
            temp[k++] = arr[left++];
        }

        // if elements on the right half are still left
        while (right <= high) {
            temp[k++] = arr[right++];
        }

        // transferring all elements from temporary to arr
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    // Function to count reverse pairs in the array
    public static int countPairs(int[] arr, int low, int mid, int high) {
        int right = mid + 1; // starting index of right half of arr
        int cnt = 0; // count of reverse pairs

        // iterate over the left half of the array
        for (int i = low; i <= mid; i++) {
            // find the first element in the right half that is not a reverse pair
            while (right <= high && arr[i] > 2 * (long) arr[right]) { // cast to long to avoid overflow
                right++;
            }
            // count the number of reverse pairs
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    // Function to perform merge sort and count reverse pairs
    public static int mergeSort(int[] arr, int low, int high) {
        int cnt = 0; // count of reverse pairs
        if (low >= high) return cnt; // base case: if the array has one or no elements
        int mid = (low + high) / 2; // find the middle index

        // recursively sort the left half and count reverse pairs
        cnt += mergeSort(arr, low, mid);  
        // recursively sort the right half and count reverse pairs
        cnt += mergeSort(arr, mid + 1, high); 
        // count reverse pairs between the two halves
        cnt += countPairs(arr, low, mid, high); 
        // merge the two sorted halves
        merge(arr, low, mid, high);  
        return cnt;
    }

    // Main function to count reverse pairs in the array
    public int reversePairs(int[] nums) {
        return mergeSort(nums, 0, nums.length - 1);
    }
}
/*
Explanation:
merge Function:
Temporary Array: Creates a temporary array to store the merged result.
Left and Right Pointers: Initializes pointers for the left and right halves of the array.
Merging: Merges the elements from the left and right halves in a sorted manner.
Remaining Elements: Adds any remaining elements from the left or right half to the temporary array.
Transfer: Transfers the sorted elements from the temporary array back to the original array.
countPairs Function:
Right Pointer: Initializes the pointer for the right half of the array.
Count: Initializes the count of reverse pairs.
Iterate Left Half: Iterates over the left half of the array.
Find Reverse Pairs: Finds the first element in the right half that is not a reverse pair and counts the number of reverse pairs.
mergeSort Function:
Base Case: Checks if the array has one or no elements.
Mid Index: Finds the middle index of the array.
Recursive Sort: Recursively sorts the left and right halves of the array and counts reverse pairs.
Count Reverse Pairs: Counts reverse pairs between the two halves.
Merge: Merges the two sorted halves.
reversePairs Function:
Main Function: Calls the mergeSort function to count reverse pairs in the array.
*/

