//https://www.naukri.com/code360/problems/search-in-a-rotated-sorted-array-ii_7449547
bool searchInARotatedSortedArrayII(vector<int>&A, int key) {
    // Write your code here.
    int n = A.size(); // size of the array.
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if mid points the target
        if (A[mid] == key) return true;

        //Edge case:
        if (A[low] == A[mid] && A[mid] == A[high]) {
            low = low + 1;
            high = high - 1;
            continue;
        }

        //if left part is sorted:
        if (A[low] <= A[mid]) {
            if (A[low] <= key && key <= A[mid]) {
                //element exists:
                high = mid - 1;
            }
            else {
                //element does not exist:
                low = mid + 1;
            }
        }
        else { //if right part is sorted:
            if (A[mid] <= key && key <= A[high]) {
                //element exists:
                low = mid + 1;
            }
            else {
                //element does not exist:
                high = mid - 1;
            }
        }
    }
    return false;
}
