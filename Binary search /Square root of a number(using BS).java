//https://www.geeksforgeeks.org/problems/square-root/0

// Function to find square root
// x: element to find square root
class Solution {
    long floorSqrt(long n) {
        // Your code here
    long low =0 , high =n;
    while(low <= high){
         long mid = (low + high)/2;
         long val = mid* mid;
        if(val <= n){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return high;
    }
}
