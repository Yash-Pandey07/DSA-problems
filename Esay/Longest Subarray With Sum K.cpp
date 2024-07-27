//https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int left=0,right =0;
    long long sum=a[0];
    int maxLen = 0;
    int n = a.size();
    while(right<n){
        while(left<=right && sum>k){
            sum-=a[left];
            left++;
        }
        if(sum ==k){
            maxLen = max(maxLen, right-left+1);
        }
        right++;
        if(right<n){
            sum += a[right];
        }
        
    }
    return maxLen;
}
