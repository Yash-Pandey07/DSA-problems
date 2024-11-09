//https://www.naukri.com/code360/problems/largest-subarray-sum-minimized_7461751
#include <bits/stdc++.h>
using namespace std;

int countPartitions(vector<int> &arr, int maxSum) {
    int n = arr.size(); //size of array.
    int students = 1;
    long long subarraySum  = 0;
    for (int i = 0; i < n; i++) {
        if (subarraySum  + arr[i] <= maxSum) {
            subarraySum  += arr[i];
        }
        else {
            students++;
            subarraySum  = arr[i];
        }
    }
    return students;
}

int largestSubarraySumMinimized(vector<int> & arr, int n, int m){
    //ifm>n
    if(m>n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end() ,0);

    while(low<=high){
        int mid = (low+high)/2;
        int subarray = countPartitions(arr ,mid);
        if(subarray > m){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return low;
}

int largestSubarraySumMinimized(vector<int> a, int k) {
    // Write Your Code Here
    return largestSubarraySumMinimized(a, a.size(), k);
    
}
