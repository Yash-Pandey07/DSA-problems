//Question link:-https://www.naukri.com/code360/problems/two-sum_839653
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <utility> 
#include <bits/stdc++.h>
vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n)
{
  sort(arr.begin(), arr.end());
  vector<pair<int, int>> ans;

  int i = 0, j = n - 1;
  int sum = 0;
  bool found = false;

  while (i < j) {
    sum = arr[i] + arr[j];
    if (sum < target)
      i++;
    else if (sum > target)
      j--;
    else if (sum == target) {
      ans.push_back(make_pair(arr[i], arr[j]));
	  i++;
	  j--;
	  found = true;
    }
  }

  if(found == false)
  	ans.push_back(make_pair(-1, -1));

  return ans;
}
