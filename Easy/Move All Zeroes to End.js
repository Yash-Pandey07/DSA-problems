//https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/move-all-zeroes-to-end-of-array0751
class Solution {
    pushZerosToEnd(arr) {
        // code here
        
    let count = 0;
    for(let  i=0; i< arr.length;i++){
        if(arr[i]!==0){
            arr[count]= arr[i];
            count++;
        }
    }
        while(count < arr.length){
            arr[count] = 0;
            count++;
        }
        
        return arr;
        
    }
}
