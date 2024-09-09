//https://www.naukri.com/code360/problems/missing-and-repeating-numbers_6828164
#include <vector>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    long long n = a.size();
    
    // Calculate the sum of the first n natural numbers
    long long SN = (n * (n + 1)) / 2;
    
    // Calculate the sum of the squares of the first n natural numbers
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    long long S = 0, S2 = 0;

    // Calculate the sum and sum of squares of the array elements
    for (int i = 0; i < n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }

    // Calculate the difference between the sums
    long long val1 = S - SN;
    long long val2 = S2 - S2N;

    // Calculate the sum of the missing and repeating numbers
    val2 = val2 / val1;

    // Calculate the repeating number
    long long x = (val1 + val2) / 2;
    
    // Calculate the missing number
    long long y = x - val1;

    // Return the repeating and missing numbers
    return {(int)x, (int)y};
}
