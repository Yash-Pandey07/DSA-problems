//https://www.naukri.com/code360/problems/unique-element-in-sorted-array_1112654
int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	int n= arr.size();

	if(n==1) return arr[0];

	if(arr[0] != arr[1]) return arr[0];
	if(arr[n-1] != arr[n-2]) return arr[n-1];

	int low =1, high=n-2;
	while(low<= high){
		int mid = (low+high)/2;
		if(arr[mid] != arr[mid+1] && arr[mid]!= arr[mid-1]){
			return arr[mid];
		}
		//left side
		if((mid%2==1 && arr[mid]==arr[mid-1]) ||(mid%2==0 && arr[mid]==arr[mid+1])){
			low=mid+1;
		}
		//right side
		else{
			high=mid-1;
		}
	}
	return -1;
}
