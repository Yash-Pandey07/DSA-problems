//
//optimize solution

//Better solution
class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int n = nums.length; //size of the array
        List<Integer> ls = new ArrayList<>(); // list of answers

        //declaring a map:
        HashMap<Integer, Integer> mpp = new HashMap<>();

        // least occurrence of the majority element:
        int mini = (int)(n / 3) + 1;

        //storing the elements with its occurnce:
        for (int i = 0; i < n; i++) {
            int value = mpp.getOrDefault(nums[i], 0);
            mpp.put(nums[i], value + 1);

            //checking if v[i] is
            // the majority element:
            if (mpp.get(nums[i]) == mini) {
                ls.add(nums[i]);
            }
            if (ls.size() == 2) break;
        }

        return ls;
    }
}
