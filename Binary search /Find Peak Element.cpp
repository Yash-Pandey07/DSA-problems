//https://www.naukri.com/code360/problems/find-peak-element_1081482
int findPeakElement(vector<int> &arr) {
    // Write your code here
    int n = arr.size();
    //check if it only 1 element or 1st element is peak or last element is peak only
    if(n==1) return 0;
    if(arr[0] > arr[1]) return 0;
    if(arr[n-1] > arr[n-2]) return n-1;
    //Checking the array and reducing the low or high
    int low=1, high= n-2;
    while(low <= high) {
        int mid= (low+high)/2;
        if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]){
            return mid;
        }
        else if(arr[mid] > arr[mid-1]){
            low = mid -1;
        }
        else {
            high = mid-1;
        }
    }
    return -1;
}
