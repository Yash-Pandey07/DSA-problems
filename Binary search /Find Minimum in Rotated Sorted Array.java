//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
class Solution {
    public int findMin(int[] nums) {
    
    int low =0, high = nums.length -1;
	int ans =  Integer.MAX_VALUE;

	while(low <= high){
		int mid =(low + high)/2;

        //added one more check to stop futher binary search
        while(nums[low] <= nums[high]){
			ans =  Math.min(ans, nums[low]);
			break ;
		}

		//checking left side is sorted or not
		if(low <= high){
			mid = (low + high)/2;
			
			if(nums[low] <= nums[mid]){
				ans = Math.min(ans,nums[low]);
				low = mid+1;
			}
			else{
				high = mid-1 ;
				ans = Math.min(ans, nums[mid]);
			}
		}
	}
	return ans;
    }
}
