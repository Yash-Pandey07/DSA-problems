//https://www.naukri.com/code360/problems/merge-two-sorted-arrays-without-extra-space_6898839
#include<vector>
#include <algorithm> 
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	// Write your code here.

	int n = a.size();
    int m = b.size();
	//Declare 2 pointers:
	
    int left = n - 1;
    int right = 0;

    //Swap the elements until a[left] is
    // smaller than b[right]:
    while (left >= 0 && right < m) {
        if (a[left] > b[right]) {
            swap(a[left], b[right]);
            left--, right++;
        }
        else {
            break;
        }
    }

    // Sort a[] and b[] individually:
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
	
}
