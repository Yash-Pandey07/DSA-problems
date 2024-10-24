//https://www.naukri.com/code360/problems/kth-missing-element_893215
//Brute Force Approach
int missingK(vector < int > vec, int n, int k) {
    // Write your code here.
    for(int i=0;i<n;i++){
        if(vec[i] <= k)k++;
        else break;
    }
    return k;
}
