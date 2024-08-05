//https://www.naukri.com/code360/problems/alternate-numbers_6783445
vector<int> alternateNumbers(vector<int>&a) {
    // Write your code here.
    int n = a.size();
    vector<int> pos,neg;
    for(int i = 0; i < n; i++){
         if(a[i] > 0){
            pos.push_back(a[i]);
        }
        else {
            neg.push_back(a[i]);
        }
    }

    if(pos.size() > neg.size()) {
        for(int i = 0; i<neg.size(); i++){
            a[2*i] = pos[i];
            a[2*i+1] = neg[i];
        }
        int index = neg.size() * 2;
        for(int i=neg.size();i<pos.size();i++){
            a[index] = pos[i];
            index++;
        }
    }
    else{
        for(int i = 0; i<pos.size(); i++){
            a[2*i] = pos[i];
            a[2*i+1] = neg[i];
        }
        int index = pos.size() * 2;
        for(int i=pos.size();i<neg.size();i++){
            a[index] = neg[i];
            index++;
        }
    }

    return a;

}