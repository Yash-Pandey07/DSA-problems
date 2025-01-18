class Solution {
    int max =0, start =0, end=0;
        public boolean isPalindrome(String s , int i , int j){
            while(i<j){
                char char1 = s.charAt(i);
                char char2 = s.charAt(j);

                if(char1 != char2){
                    return false;
                }
                i++;
                j--;
            }
            return true;
        }

    public String longestPalindrome(String s) {
        int n = s.length();
        for(int i=0;i<n;i++){
            for(int j=i; j<n;j++){
                if(isPalindrome(s,i,j)==true){
                    if(j-i+1 > max){
                        max = j-i+1;
                        start = i;
                        end  = j;
                    }
                }
            }
        }
        return s.substring(start ,end +1);
    }
}
