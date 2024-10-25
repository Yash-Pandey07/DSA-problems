//https://www.naukri.com/code360/problems/kth-missing-element_893215
//Brute Force Approach
int missingK(vector < int > vec, int n, int k) {
    // Write your code here.
    //brute force
    // for(int i=0;i<n;i++){
    //     if(vec[i] <= k)k++;
    //     else break;
    // }
    // return k;

    //BS
    int low=0, high=n-1;
    while(low<= high){
        int mid = (low+high)/2;
        int missing = vec[mid]- (mid+1);
        if(missing <k){
            low= mid+1;
        }
        else high= mid-1;
    }
   // return high +1 + k;           //for edge case we should not use this as high can be negative number too.
    return low +k;
}
