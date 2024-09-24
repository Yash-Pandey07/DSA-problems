//https://www.naukri.com/code360/problems/first-and-last-position-of-an-element-in-sorted-array_1082549
#include <bits/stdc++.h> 
int firstOccurance(vector<int> arr, int n, int k) {
    int low = 0, high = n - 1;
    int first = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k) {
            first = mid;
            high = mid - 1; // look for smaller index on the left
        } else if (arr[mid] < k) {
            low = mid + 1; // look on the right
        } else {
            high = mid - 1;
        }
    }
    return first;
}

int lastOccurance(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int last = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k) {
            last = mid;
            low = mid + 1; // look for larger index on the right
        } else if (arr[mid] < k) {
            low = mid + 1; // look on the right
        } else {
            high = mid - 1;
        }
    }
    return last;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    int first = firstOccurance(arr, n, k);
    if (first == -1) return {-1, -1};
    int last = lastOccurance(arr, n, k);
    return {first, last};
}
