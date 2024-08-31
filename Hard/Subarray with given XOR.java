//https://www.interviewbit.com/problems/subarray-with-given-xor/
public class Solution {
    public int solve(ArrayList<Integer> A, int B) {
        int xr = 0;
        int count = 0;
        HashMap<Integer, Integer> mpp = new HashMap<>();
        mpp.put(xr, 1);

        for (int i = 0; i < A.size(); i++) {
            xr = xr ^ A.get(i);
            int x = xr ^ B;
            count += mpp.getOrDefault(x, 0);
            mpp.put(xr, mpp.getOrDefault(xr, 0) + 1);
        }

        return count;
    }
}
