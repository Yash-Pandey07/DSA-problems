//https://www.naukri.com/code360/problems/sort-an-array-of-0s-1s-and-2s_892977
#include <bits/stdc++.h> 
void sortArray(vector<int>& arr, int n)
{
    // Write your code here
        int low=0;
        int mid=0;
        int high =n-1;
        while(mid<=high){
            if(arr[mid]==0){
                swap(arr[low],arr[mid]);
                low++;mid++;
            }
            else if(arr[mid]==1){
                mid++;
            }
            else if(arr[mid]==2){
                swap(arr[mid],arr[high]);
                high--;
            }
        }
}
    
