var isPalindrome = function(s) {
    let s1 = s.replace(/[^a-zA-Z0-9]/g, '').toLowerCase();
    let n = s1.length;
    for(let i=0;i<s1.length;i++){
        if(s1[i] != s1[n-i-1]){
            return false;
        }
    }
    return true;
};
