//https://www.naukri.com/code360/problems/algorithm-to-find-best-insert-position-in-sorted-array_839813
int searchInsert(vector<int>& arr, int m) {
    int n = arr.size();
    int s = 0, e = n-1;
    int mid = s+(e-s)/2;
    int ans = n;
    while(s<=e){
        if(arr[mid]==m){
            return mid;
        }
        else if(arr[mid]>=m){
            ans = mid ;
            e = mid-1;
        }
        else{
            s= mid+1;
        }
        mid = s+(e-s)/2;
    }
    return ans ;
}
