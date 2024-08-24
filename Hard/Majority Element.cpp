//https://www.naukri.com/code360/problems/majority-element_6915220
//Optimize solution
int cnt1 = 0, cnt2 =0;
	int el1 = INT_MIN;
	int el2 = INT_MIN;

	for(int i=0;i<v.size();i++){
		if(cnt1 ==0 && el2 != v[i]){
			cnt1 = 1;
			el1  = v[i];
		}
		else if (cnt2 == 0 && el1 != v[i]){
			cnt2 = 1;
			el2	 = v[i]; 
		}
		else if (v[i] == el1) cnt1++;
		else if (v[i] == el2) cnt2++;
		else{
			cnt1--,cnt2--;
		}
	}
	vector<int> ls;
	cnt1 =0,cnt2=0;
	for(int i =0;i<v.size(); i++){
		if(el1 == v[i]) cnt1++;
		if(el2 == v[i]) cnt2++;
	}
	int mini = (int)(v.size()/3) +1;
	if(cnt1 >= mini) ls.push_back(el1);
	if(cnt2 >= mini) ls.push_back(el2);	
	sort(ls.begin() , ls.end());
	return ls;


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
