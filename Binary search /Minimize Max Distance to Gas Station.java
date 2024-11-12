//https://takeuforward.org/arrays/minimise-maximum-distance-between-gas-stations/

//optimal
import java.util.*;

public class tUf {
    public static int numberOfGasStationsRequired(double dist, int[] arr) {
        int n = arr.length; // size of the array
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            int numberInBetween = (int)((arr[i] - arr[i - 1]) / dist);
            if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
                numberInBetween--;
            }
            cnt += numberInBetween;
        }
        return cnt;
    }

    public static double minimiseMaxDistance(int[] arr, int k) {
        int n = arr.length; // size of the array
        double low = 0;
        double high = 0;

        //Find the maximum distance:
        for (int i = 0; i < n - 1; i++) {
            high = Math.max(high, (double)(arr[i + 1] - arr[i]));
        }

        //Apply Binary search:
        double diff = 1e-6 ;
        while (high - low > diff) {
            double mid = (low + high) / (2.0);
            int cnt = numberOfGasStationsRequired(mid, arr);
            if (cnt > k) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return high;
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5};
        int k = 4;
        double ans = minimiseMaxDistance(arr, k);
        System.out.println("The answer is: " + ans);
    }
}





//better aproach
// import java.util.*;

// public class tUf {
//     public static class Pair {
//         double first;
//         int second;

//         Pair(double first, int second) {
//             this.first = first;
//             this.second = second;
//         }
//     }

//     public static double minimiseMaxDistance(int[] arr, int k) {
//         int n = arr.length; // size of array.
//         int[] howMany = new int[n - 1];
//         PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> Double.compare(b.first, a.first));

//         // insert the first n-1 elements into pq
//         // with respective distance values:
//         for (int i = 0; i < n - 1; i++) {
//             pq.add(new Pair(arr[i + 1] - arr[i], i));
//         }

//         // Pick and place k gas stations:
//         for (int gasStations = 1; gasStations <= k; gasStations++) {
//             // Find the maximum section
//             // and insert the gas station:
//             Pair tp = pq.poll();
//             int secInd = tp.second;

//             // insert the current gas station:
//             howMany[secInd]++;

//             double inidiff = arr[secInd + 1] - arr[secInd];
//             double newSecLen = inidiff / (double) (howMany[secInd] + 1);
//             pq.add(new Pair(newSecLen, secInd));
//         }

//         return pq.peek().first;
//     }

//     public static void main(String[] args) {
//         int[] arr = {1, 2, 3, 4, 5};
//         int k = 4;
//         double ans = minimiseMaxDistance(arr, k);
//         System.out.println("The answer is: " + ans);
//     }
// }

