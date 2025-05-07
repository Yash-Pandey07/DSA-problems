//https://leetcode.com/problems/two-sum/description/

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const hMap = new Map();
    for(let i=0; i<nums.length;i++){
        let compliments = target - nums[i];
        if(hMap.has(compliments)){
            return  [hMap.get(compliments),i];
        }
    hMap.set(nums[i],i);
    }
    
};
