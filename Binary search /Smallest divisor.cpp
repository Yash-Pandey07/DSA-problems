//https://www.naukri.com/code360/problems/smallest-divisor-with-the-given-limit_1755882
#include<bits/stdc++.h>
int sumByD(vector<int> &arr, int div){
	int sum =0;
	int n= arr.size();
	for(int i =0; i< n;i++){
		sum += ceil((double) (arr[i]) / (double)(div));
	}
	return sum;
}

int smallestDivisor(vector<int>& arr, int limit)
{
	// Write your code here.
	int low = 1, high = *max_element(arr.begin(), arr.end());
	while(low <= high){
		int mid = (low+high)/2;
		if(sumByD(arr, mid) <= limit){
			high= mid -1;
		}else{
			low = mid + 1;
		}
	}
	return low;
	
}
