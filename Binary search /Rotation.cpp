//https://www.naukri.com/code360/problems/rotation_7449070
#include<bits/stdc++.h>
int findKRotation(vector<int> &arr){
    // Write your code here.  
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index=-1;
    while (low <= high) {
        int mid = (low + high) / 2;

         //added one more check to stop futher binary search
		while(arr[low] <= arr[high]){
            // ans =  min(ans, arr[low]);
			if(arr[low]<ans){
                ans= arr[low];
                index =low;
            }
            break;
		}

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            // ans = min(ans, arr[low]);
            if(arr[low]<ans){
                ans= arr[low];
                index =low;
            }

            // Eliminate left half:
            low = mid + 1;
        }
        else { //if right part is sorted:

            // keep the minimum:
            //ans = min(ans, arr[mid]);
            if(arr[mid]<ans){
                ans= arr[mid];
                index =mid;
            }

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return index;
  
}
