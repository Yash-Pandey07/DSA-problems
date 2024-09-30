//https://www.naukri.com/code360/problems/occurrence-of-x-in-a-sorted-array_630456
#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int>& arr, int n, int k) {
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

int lastOccurrence(vector<int>& arr, int n, int k) {
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

int countOccurrences(vector<int>& arr, int n, int x) {
    int first = firstOccurrence(arr, n, x);
    if (first == -1) return 0; // x is not present in the array
    int last = lastOccurrence(arr, n, x);
    return (last - first + 1);
}

int main() {
    vector<int> arr = {1, 1, 1, 2, 2, 3, 3};
    int n = arr.size();
    int x = 3;
    cout << "Total occurrences of " << x << " is " << countOccurrences(arr, n, x) << endl;
    return 0;
}
