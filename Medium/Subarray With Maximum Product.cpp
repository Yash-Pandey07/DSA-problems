//https://www.naukri.com/code360/problems/subarray-with-maximum-product_6890008
#include<vector>
#include <bits/stdc++.h>
int subarrayWithMaxProduct(vector<int> &arr){
	// Write your code here.
        int pre =1, suff =1;
        int ans =INT_MIN;

        int n =arr.size();
        for(int i =0;i<n;i++){
            if(pre ==0) pre=1;
            if(suff==0) suff=1;

            pre = pre * arr[i];
            suff = suff * arr[n-i-1];
            ans = max(ans, max(pre ,suff)); 
        }
        return ans;
}
