//https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
class Solve {
    int[] findTwoElement(int arr[]) {
        int n = arr.length;
        int xor = 0;

        // XOR all array elements and numbers from 1 to n
        for (int i = 0; i < n; i++) {
            xor ^= arr[i];
        }
        for (int i = 1; i <= n; i++) {
            xor ^= i;
        }

        // Find the rightmost set bit in xor
        int setBit = xor & ~(xor - 1);

        int x = 0, y = 0;

        // Divide elements into two sets and XOR separately
        for (int i = 0; i < n; i++) {
            if ((arr[i] & setBit) != 0) {
                x ^= arr[i];
            } else {
                y ^= arr[i];
            }
        }
        for (int i = 1; i <= n; i++) {
            if ((i & setBit) != 0) {
                x ^= i;
            } else {
                y ^= i;
            }
        }

        // Determine which is the missing number and which is the repeating number
        int[] result = new int[2];
        for (int i = 0; i < n; i++) {
            if (arr[i] == x) {
                result[0] = x; // Repeating number
                result[1] = y; // Missing number
                break;
            } else if (arr[i] == y) {
                result[0] = y; // Repeating number
                result[1] = x; // Missing number
                break;
            }
        }

        return result;
    }
}
