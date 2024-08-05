//https://www.naukri.com/code360/problems/reading_6845742
#include <map>
string read(int n, vector<int> nums, int target)
{
    // Write your code here.
    map<int,int> mpp ; 
    for (int i = 0; i < n; i++) {
        int complement = target - nums[i];
        if(mpp.find(complement) != mpp.end()){
            return "YES";
        }
        mpp[nums[i]]= i;
    }
    return "NO";
}
