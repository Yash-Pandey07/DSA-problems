//https://www.naukri.com/code360/problems/count-subarrays-with-given-xor_1115652
#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int k)
{
    //    Write your code here.
    int xr = 0;
    int count =0;
    unordered_map<int , int > mpp;      //map time complexity is more so use unordered map
    mpp[xr]++;

    for(int i=0;i<arr.size();i++){
        xr = xr ^ arr[i];
        int x = xr ^ k;
        count += mpp[x];
        mpp[xr]++;
    }

    return count;
}
