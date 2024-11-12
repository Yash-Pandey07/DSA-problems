//https://www.naukri.com/code360/problems/minimise-max-distance_7541449

#include <bits/stdc++.h>
using namespace std;
//optimal
int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
    int n = arr.size(); // size of the array
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size(); // size of the array
    long double low = 0;
    long double high = 0;

    //Find the maximum distance:
    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    //Apply Binary search:
    long double diff = 1e-6 ;
    while (high - low > diff) {
        long double mid = (low + high) / (2.0);
        int cnt = numberOfGasStationsRequired(mid, arr);
        if (cnt > k) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return high;
}


//better 
// long double minimiseMaxDistance(vector<int> &arr, int k) {
//     int n = arr.size(); //size of array.
//     vector<int> howMany(n - 1, 0);
//     priority_queue<pair<long double, int>> pq;

//     //insert the first n-1 elements into pq
//     //with respective distance values:
//     for (int i = 0; i < n - 1; i++) {
//         pq.push({arr[i + 1] - arr[i], i});
//     }

//     //Pick and place k gas stations:
//     for (int gasStations = 1; gasStations <= k; gasStations++) {
//         //Find the maximum section
//         //and insert the gas station:
//         auto tp = pq.top();
//         pq.pop();
//         int secInd = tp.second;

//         //insert the current gas station:
//         howMany[secInd]++;

//         long double inidiff = arr[secInd + 1] - arr[secInd];
//         long double newSecLen = inidiff / (long double)(howMany[secInd] + 1);
//         pq.push({newSecLen, secInd});
//     }

//     return pq.top().first;
// }


// Brute FOrce
// long double minimiseMaxDistance(vector<int> &arr, int k) {
//     int n = arr.size(); //size of array.
//     vector<int> howMany(n - 1, 0);

//     //Pick and place k gas stations:
//     for (int gasStations = 1; gasStations <= k; gasStations++) {
//         //Find the maximum section
//         //and insert the gas station:
//         long double maxSection = -1;
//         int maxInd = -1;
//         for (int i = 0; i < n - 1; i++) {
//             long double diff = arr[i + 1] - arr[i];
//             long double sectionLength =
//                 diff / (long double)(howMany[i] + 1);
//             if (sectionLength > maxSection) {
//                 maxSection = sectionLength;
//                 maxInd = i;
//             }
//         }
//         //insert the current gas station:
//         howMany[maxInd]++;
//     }

//     //Find the maximum distance i.e. the answer:
//     long double maxAns = -1;
//     for (int i = 0; i < n - 1; i++) {
//         long double diff = arr[i + 1] - arr[i];
//         long double sectionLength =
//             diff / (long double)(howMany[i] + 1);
//         maxAns = max(maxAns, sectionLength);
//     }
//     return maxAns;
// }

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}

