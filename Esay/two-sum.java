//https://leetcode.com/problems/two-sum/description/
class Solution {
    public int[] twoSum(int[] nums, int target) {
        //Arrays.sort(nums);
        int[] arr= new int[2];
        // for(int i=0;i<nums.length;i++){          //O(n^2)
        //     int Newtarget=target-nums[i];
        //     for(int j=i+1;j<nums.length;j++){
        //         if(nums[j]==Newtarget){
        //             arr[0]=i;
        //             arr[1]=j;
        //             return arr;
        //         }
        //     }
        // }
        Map<Integer, Integer> map = new HashMap<>();    //O(n)
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement)) {
                return new int[] { map.get(complement), i };
            }
            map.put(nums[i], i);
        }
        return arr;
    }
}
