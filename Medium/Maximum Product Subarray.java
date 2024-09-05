//https://leetcode.com/problems/maximum-product-subarray/description/
class Solution {
    public int maxProduct(int[] nums) {
        int pre =1, suff =1;
        int ans =Integer.MIN_VALUE;

        int n =nums.length;
        for(int i =0;i<n;i++){
            if(pre ==0) pre=1;
            if(suff==0) suff=1;

            pre = pre * nums[i];
            suff = suff * nums[n-i-1];
            ans = Math.max(ans, Math.max(pre ,suff)); 
        }
        return ans;
    }
}

//Brute Force
// import java.util.*;
// public class Main
// {
// 	static int maxProductSubArray(int arr[]) {
// 	    int result = Integer.MIN_VALUE;
// 	    for(int i=0;i<arr.length-1;i++) 
// 	        for(int j=i+1;j<arr.length;j++) {
// 	            int prod = 1;
// 	            for(int k=i;k<=j;k++) 
// 	                prod *= arr[k];
// 	            result = Math.max(result,prod);
// 	        }
// 	   return result;     
// 	}
// 	public static void main(String[] args) {
// 		int nums[] = {1,2,-3,0,-4,-5};
// 		int answer = maxProductSubArray(nums);
// 		System.out.print("The maximum product subarray is: "+answer);
// 	}
// }

