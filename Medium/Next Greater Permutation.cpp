#include <vector>
//https://www.naukri.com/code360/problems/next-greater-permutation_6929564

vector<int> nextGreaterPermutation(vector<int> &A) {
    // Initialize index to -1, which will be used to store the position
    // where the next greater permutation needs to be found
    int index = -1;
    int n = A.size();

    // Find the first index from the end where the current element is less than the next element
    for(int i = n-2; i >= 0; i--){
        if(A[i] < A[i+1]){
            index = i;
            break;
        }
    }

    // If no such index is found, reverse the entire array to get the smallest permutation
    if(index == -1){
        reverse(A.begin(), A.end());
        return A;
    }

    // Find the first element from the end that is greater than the element at the found index
    for(int i = n-1; i >= 0; i--){
        if(A[i] > A[index]){
            swap(A[i], A[index]);
            break;
        }
    }

    // Reverse the elements after the found index to get the next permutation
    reverse(A.begin() + index + 1, A.end());
    return A;
}
