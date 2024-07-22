//https://leetcode.com/problems/move-zeroes/description/
import java.util.*;
class Solution {
    public void moveZeroes(int[] nums) {
        int a=-1;
        int n =nums.length;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                swap(nums,++a,i);
            }
        }
    }
    private void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
