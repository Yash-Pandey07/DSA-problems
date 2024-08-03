//https://www.naukri.com/code360/problems/630526
long long maxSubarraySum(vector<int> arr, int n)
{
    // Write your code here.
    long long sum=0,maxi=INT_MIN;
    long long maxStart=-1,maxEnd=-1;
    for(int i=0;i<arr.size();i++){
        if(sum==0) maxStart =i;
        sum+=arr[i];
        if(sum>maxi){
            maxi=sum;
            maxEnd=i;
        }
        if(sum<0){
            sum=0;
        }
        
    }
    //cout<<maxStart<<" "<<maxEnd<<endl;
    if (maxi < 0) maxi = 0;
    return maxi;
}
