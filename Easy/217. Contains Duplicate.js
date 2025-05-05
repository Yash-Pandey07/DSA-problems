// https://leetcode.com/problems/contains-duplicate/
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    const hset = new Set();
    for(let i=0;i<=nums.length;i++){
        if(hset.has(nums[i])){
            return true
        }
        hset.add(nums[i])
    }
    return false
};
