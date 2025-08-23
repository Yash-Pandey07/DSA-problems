//https://leetcode.com/problems/longest-palindromic-substring/description/

/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    if (s.length <= 1) return s;

    let start = 0, end = 0;

    // Expand around the given center
    function expandFromCenter(left, right) {
        while (left >= 0 && right < s.length && s[left] === s[right]) {
            left--;
            right++;
        }
        return [left + 1, right - 1]; // return palindrome boundaries
    }

    for (let i = 0; i < s.length; i++) {
        // Odd-length palindromes (center at i)
        let [l1, r1] = expandFromCenter(i, i);

        // Even-length palindromes (center between i and i+1)
        let [l2, r2] = expandFromCenter(i, i + 1);

        // Update max palindrome if found bigger
        if (r1 - l1 > end - start) [start, end] = [l1, r1];
        if (r2 - l2 > end - start) [start, end] = [l2, r2];
    }

    return s.substring(start, end + 1);
};
