//https://www.naukri.com/code360/problems/minimise-max-distance_7541449

#include <bits/stdc++.h> // Includes all standard libraries
using namespace std;

// Optimal solution
int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
    int n = arr.size(); // Size of the array
    int cnt = 0; // Counter for the number of gas stations required
    for (int i = 1; i < n; i++) {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist); // Calculate the number of gas stations needed between two points
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
            numberInBetween--; // Adjust if the distance is exactly divisible
        }
        cnt += numberInBetween; // Add to the total count
    }
    return cnt; // Return the total number of gas stations required
}

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size(); // Size of the array
    long double low = 0; // Initialize low to 0
    long double high = 0; // Initialize high to 0

    // Find the maximum distance between consecutive points
    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    // Apply binary search to find the minimum possible maximum distance
    long double diff = 1e-6; // Precision for binary search
    while (high - low > diff) {
        long double mid = (low + high) / 2.0; // Calculate mid point
        int cnt = numberOfGasStationsRequired(mid, arr); // Get the number of gas stations required for this mid distance
        if (cnt > k) {
            low = mid; // If more gas stations are required, increase low
        } else {
            high = mid; // Otherwise, decrease high
        }
    }
    return high; // Return the minimized maximum distance
}

// Better solution using priority queue
// long double minimiseMaxDistance(vector<int> &arr, int k) {
//     int n = arr.size(); // Size of the array
//     vector<int> howMany(n - 1, 0); // Vector to keep track of gas stations in each section
//     priority_queue<pair<long double, int>> pq; // Max heap to store sections with their respective distances

//     // Insert the first n-1 elements into the priority queue with respective distance values
//     for (int i = 0; i < n - 1; i++) {
//         pq.push({arr[i + 1] - arr[i], i}); // Push the distance between consecutive gas stations and their index
//     }

//     // Pick and place k gas stations
//     for (int gasStations = 1; gasStations <= k; gasStations++) {
//         // Find the maximum section and insert the gas station
//         auto tp = pq.top(); // Get the section with the maximum distance
//         pq.pop(); // Remove it from the priority queue
//         int secInd = tp.second; // Get the index of the section

//         // Insert the current gas station
//         howMany[secInd]++; // Increment the count of gas stations in this section

//         long double inidiff = arr[secInd + 1] - arr[secInd]; // Initial distance of the section
//         long double newSecLen = inidiff / (long double)(howMany[secInd] + 1); // New section length after adding the gas station
//         pq.push({newSecLen, secInd}); // Push the new section length back into the priority queue
//     }

//     return pq.top().first; // Return the maximum distance after placing all gas stations
// }

// Brute force solution
// long double minimiseMaxDistance(vector<int> &arr, int k) {
//     int n = arr.size(); // Size of the array
//     vector<int> howMany(n - 1, 0); // Vector to keep track of gas stations in each section

//     // Pick and place k gas stations
//     for (int gasStations = 1; gasStations <= k; gasStations++) {
//         // Find the maximum section and insert the gas station
//         long double maxSection = -1; // Initialize max section length
//         int maxInd = -1; // Initialize index of max section
//         for (int i = 0; i < n - 1; i++) {
//             long double diff = arr[i + 1] - arr[i]; // Calculate the distance between consecutive points
//             long double sectionLength = diff / (long double)(howMany[i] + 1); // Calculate the section length after adding gas stations
//             if (sectionLength > maxSection) {
//                 maxSection = sectionLength; // Update max section length
//                 maxInd = i; // Update index of max section
//             }
//         }
//         // Insert the current gas station
//         howMany[maxInd]++; // Increment the count of gas stations in this section
//     }

//     // Find the maximum distance i.e. the answer
//     long double maxAns = -1; // Initialize max answer
//     for (int i = 0; i < n - 1; i++) {
//         long double diff = arr[i + 1] - arr[i]; // Calculate the distance between consecutive points
//         long double sectionLength = diff / (long double)(howMany[i] + 1); // Calculate the section length after adding gas stations
//         maxAns = max(maxAns, sectionLength); // Update max answer
//     }
//     return maxAns; // Return the maximum distance
// }

int main() {
    vector<int> arr = {1, 2, 3, 4, 5}; // Example array of gas station positions
    int k = 4; // Number of gas stations to be placed
    long double ans = minimiseMaxDistance(arr, k); // Call the function to get the answer
    cout << "The answer is: " << ans << "\n"; // Print the answer
    return 0; // Return 0 to indicate successful execution
}
