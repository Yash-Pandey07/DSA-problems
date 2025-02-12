//https://leetcode.com/problems/valid-parentheses/description/

class Solution {
    public boolean isValid(String s) {

    HashMap<Character , Character>mappedBrackets = new HashMap<>();
    mappedBrackets.put(')', '(');
    mappedBrackets.put('}', '{');
    mappedBrackets.put(']', '[');

    Stack<Character> stackCheck = new Stack<>();

    for(int i = 0;i< s.length(); i++){
        char c = s.charAt(i);

        if(!mappedBrackets.containsKey(c)){
            stackCheck.push(c);
        }
        else{
            if(stackCheck.empty()){
                return false;
            }
            char topElement = stackCheck.pop();
            if(topElement != mappedBrackets.get(c)){
                return false;
            }
        }
    }

    return stackCheck.isEmpty();
    }
}
