//https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1
//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class Solution {

    // Function to find floor of x
    // arr: input array
    // n is the size of array
    static int findFloor(long arr[], int n, long x) {
        int low = 0, high = n - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low)/2 ;
            // maybe an answer
            if (arr[mid] <= x) {
                ans = mid;
                //look for smaller index on the left
                low = mid + 1;
            } else {
                high = mid - 1; // look on the right
            }
        }
        return ans;
    }
}
