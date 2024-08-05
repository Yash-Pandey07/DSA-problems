//https://www.naukri.com/code360/problems/majority-element_6783241
int majorityElement(vector<int> v) {
	// Write your code here
	int count=0;
	int ele=v[0];
	for(int i=0;i<v.size();i++){
		if(count==0){
			count=1;
			ele=v[i];
		}else if(v[i]==ele){
			count++;
		}else {
			count--;
		}
	}
	return ele;
}
