//https://www.naukri.com/code360/problems/intersection-of-2-arrays_1082149
import java.util.* ;
import java.io.*; 
import java.util.ArrayList;
import java.util.List;
public class Solution
{
	public static ArrayList<Integer> findArrayIntersection(ArrayList<Integer> arr1, int n, ArrayList<Integer> arr2, int m)
	{
		// Write Your Code Here.
		ArrayList<Integer> ans = new ArrayList<>();
		int i = 0, j = 0;
		while (i < n && j < m) {
            if (arr1.get(i).equals(arr2.get(j))) {
                ans.add(arr1.get(i));
                i++;
                j++;
            } else if (arr1.get(i) < arr2.get(j)) {
                i++;
            } else {
                j++;
            }
        }
	return ans;
	}
}
