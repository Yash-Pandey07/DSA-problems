//https://www.naukri.com/code360/problems/superior-elements_6783446
vector<int> superiorElements(vector<int>&a) {
    // Write your code here.
    int n= a.size();
    vector<int> ans;
    int maxi =INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(a[i]>maxi){
            ans.push_back(a[i]);
        }
        maxi=max(maxi,a[i]);
    }

    sort(ans.begin(),ans.end());
    return ans;
}
