//https://www.naukri.com/code360/problems/minimum-rate-to-eat-bananas_7449064
#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

long long calculateTotalHours(vector<int> &v, int hourly) {
    long long totalH = 0;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        totalH += (v[i] + hourly - 1) / hourly; // This avoids using ceil and ensures integer division
    }
    return totalH;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    int low = 1, high = findMax(v);
    while (low <= high) {
        int mid = low + (high - low) / 2; // Avoid potential overflow
        long long totalH = calculateTotalHours(v, mid);

        //cout << "low: " << low << ", high: " << high << ", mid: " << mid << ", totalH: " << totalH << endl;

        if (totalH <= h) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

// int main() {
//     vector<int> v = {805306368, 805306368, 805306368};
//     int h = 1000000000;
//     cout << minimumRateToEatBananas(v, h) << endl; // Expected output: 3
//     return 0;
// }
