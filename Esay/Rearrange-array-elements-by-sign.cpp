//https://leetcode.com/problems/rearrange-array-elements-by-sign/description/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int postIndex=0,negIndex=1;
        for(int i = 0; i<n; i++){
            if(nums[i]<0){
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
            else{
                ans[postIndex] = nums[i];
                postIndex +=2 ;
            }
        }
        return ans;

    }
};

// Input: nums = [3,1,-2,-5,2,-4]
// Output: [3,-2,1,-5,2,-4]