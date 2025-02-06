//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
    public int lengthOfLongestSubstring(String s) {

        if(s==null || s.length()==0){
            return 0;
        }
        if(s.length() == 1){
            return 1;
        }
        int left =0;
        int right =0;
        int max =0;

        HashSet<Character> set= new HashSet<>();

        while(right < s.length()){
            char c = s.charAt(right);
            while(set.contains(c)){
                set.remove(s.charAt(left));
                left++;
            }
            set.add(c);
            max = Math.max(max, right - left +1);
            right++;
        }
        return max;
        
    }
}
