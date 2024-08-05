//https://leetcode.com/problems/rearrange-array-elements-by-sign/description/
import java.util.Vector;
class Solution {
    public int[] rearrangeArray(int[] nums) {
        int n= nums.length;
        int [] ans = new int[n];
        int posIndex = 0, negIndex = 1;

        for(int i=0;i<n;i++){
            if(nums[i] <0){
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
            else{
                ans[posIndex] = nums[i];
                posIndex += 2;
            }
        }
        return ans;
    }
}