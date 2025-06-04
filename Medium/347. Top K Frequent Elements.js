//https://leetcode.com/problems/top-k-frequent-elements/
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var topKFrequent = function(nums, k) {
    if (k === nums.length) {
        return nums;
    }

    let count = new Map();
    nums.forEach(n => count.set(n, (count.get(n) || 0) + 1));

    let heap = Array.from(count.keys()).sort((a, b) => count.get(b) - count.get(a));

    return heap.slice(0, k);
};
