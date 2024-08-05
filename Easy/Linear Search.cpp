//https://www.naukri.com/code360/problems/linear-search_6922070
int linearSearch(int n, int num, vector<int> &arr)
{
    // Write your code here.
    if(n<0) return -1;
    for(int i=0;i<n;i++){
        if(arr[i]==num){
            return i;
        }
        
    }
    return -1;
}
