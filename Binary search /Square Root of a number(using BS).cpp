//https://www.naukri.com/code360/problems/square-root-integral_893351
int floorSqrt(int n)
{
    // Write your code here.
    int low =0 , high =n;
    while(low <= high){
        long long mid = (low + high)/2;
        long long val = mid* mid;
        if(val <= n){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return high;
}
