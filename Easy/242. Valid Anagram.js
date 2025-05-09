//https://leetcode.com/problems/valid-anagram/description/
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if (s.length !== t.length) {
        return false;
    }

    let charMap = {};

    for (let i = 0; i < s.length; i++) {
        charMap[s[i]] = (charMap[s[i]] || 0) + 1;
        charMap[t[i]] = (charMap[t[i]] || 0) - 1;
    }

    return Object.values(charMap).every(count => count === 0);
};
