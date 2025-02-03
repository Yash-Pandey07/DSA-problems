//https://leetcode.com/problems/container-with-most-water/description/

class Solution {
    public int maxArea(int[] height) {
        int n = height.length;
        int left = 0;
        int right = n-1;
        int max = 0;

        while(left<right){
            int width = right -left ;
            int area = Math.min(height[left],height[right]) * width;

            max = Math.max(max,area);

            if(height[left] <= height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return max;
    }
}
