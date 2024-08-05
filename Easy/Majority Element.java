//https://leetcode.com/problems/majority-element/description/
class Solution {
    public int majorityElement(int[] nums) {
        int count = 0;
        int ele=nums[0];
        int n = nums.length;
        for(int i=0 ;i<n;i++){
            if(count == 0){
                count = 1;
                ele = nums[i];
            }
            else if(nums[i] == ele){
                count++;
            }
            else{
                count--;
            }
        }
        return ele;
    }
}
