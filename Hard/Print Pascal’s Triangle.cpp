//https://www.naukri.com/code360/problems/print-pascal-s-triangle_6917910
vector<int> generateRow (int row){
    long long ans =1 ;
    vector<int> ansRow ;
    ansRow.push_back(1);
    for(int col =1; col<row; col++){
        ans = ans *(row - col);
        ans = ans/col;
        ansRow.push_back(ans);
    }
    return ansRow;
}
vector<vector<int>> pascalTriangle(int N) {
    // Write your code here.
    vector<vector<int>> ans;
    for(int i=1; i<=N; i++){
        ans.push_back(generateRow(i));
        //cout<<generateRow(i);
    }
    return ans;
}

//=====================================================================
//https://leetcode.com/problems/pascals-triangle/
//NON OPTIMIZE
// #include <bits/stdc++.h>
// using namespace std;

// int nCr(int n, int r) {
//     long long res = 1;

//     // calculating nCr:
//     for (int i = 0; i < r; i++) {
//         res = res * (n - i);
//         res = res / (i + 1);
//     }
//     return res;
// }

// int pascalTriangle(int r, int c) {
//     int element = nCr(r - 1, c - 1);
//     return element;
// }
