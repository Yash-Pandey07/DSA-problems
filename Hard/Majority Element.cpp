//https://www.naukri.com/code360/problems/majority-element_6915220
//Optimize solution



//Better solution 
vector<int> majorityElement(vector<int> v) {
	// Write your code here
	unordered_map<int , int> mpp;
	vector<int> ans;
	int n= v.size();
	int mini = (int) (n/3)+1;
	for(int i=0;i<n;i++){
		mpp[v[i]]++;
		if(mpp[v[i]] == mini){
			ans.push_back(v[i]);
		}
		if(ans.size()== 2) break;
	}
 	// for (const auto& entry : mpp) {
    //     cout << entry.first << " " << entry.second << endl;
    // }
	
	// for(auto it :mpp){
	// 	if(it.second > (v.size()/3)){
	// 		ans.push_back(it.first);
	// 	}
		
	// }
	sort(ans.begin() , ans.end());
	return ans;
}
