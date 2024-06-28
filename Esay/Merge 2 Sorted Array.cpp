//https://www.naukri.com/code360/problems/sorted-array_6613259
#include <vector>
#include <set>
#include <algorithm>

vector < int > sortedArray(vector < int > a, vector < int > b) {
    // Write your code here
    int n = a.size();
    int m = b.size();
    vector<int> result;
    set<int> uniqueElements;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            uniqueElements.insert(a[i]);
            i++;
        } else if (a[i] > b[j]) {
            uniqueElements.insert(b[j]);
            j++;
        } else {
            // a[i] == b[j]
            uniqueElements.insert(a[i]);
            i++;
            j++;
        }
    }
    while (i < n) {
        uniqueElements.insert(a[i]);
        i++;
    }
    while (j < m) {
        uniqueElements.insert(b[j]);
        j++;
    }
    result.assign(uniqueElements.begin(), uniqueElements.end());
    return result;
    
}
