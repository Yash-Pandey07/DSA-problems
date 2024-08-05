//https://www.naukri.com/code360/problems/ninja-and-the-zero-s_6581958
vector<int> moveZeros(int n, vector<int> a) {
    // Write your code here.
    int j=0;
    for(int i=0;i<n;i++){
       if(a[i]!=0 && i>=j){
               swap(a[i],a[j]);
               j++;
       } 
    }
    return a;
}
