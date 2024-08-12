//https://www.naukri.com/code360/problems/longest-successive-elements_6811740
int longestSuccessiveElements(vector<int>&a) {
    // Write your code here.
    if (a.size() == 0)return 0;
    sort(a.begin() , a.end());
    int n = a.size();
    int lastSmallernumber = INT_MIN;
    int count = 0;
    int longest =1;
    
    for(int i=0;i<n;i++){
        if(a[i] -1 == lastSmallernumber){
            count +=1 ;
            lastSmallernumber = a[i];
        }
        else if(lastSmallernumber != a[i]) {
            count = 1;
            lastSmallernumber = a[i];
        }
        longest = max(longest,count);
    }
    return longest;
}
