#include "bits/stdc++.h"
using namespace std;

void solve(vector<char> &input, vector<char> &taken, vector<vector<char>> &ans) {
    // base condition 
    if (input.size()==0){
        ans.push_back(taken);
        return;
    }
    
    // normal condition 
    for (int i = 0; i < input.size(); i++) {
        char temp=input[i];
        taken.push_back(temp);
        input.erase(input.begin()+i);
        solve(input,taken,ans);
        input.insert(input.begin()+i,temp);
        taken.pop_back();
    }
}
vector<vector<char>> permute(vector<char> input) {
    vector<vector<char>> ans;
     vector<char> taken;
    solve(input,taken,ans);
    return ans;
}

int32_t main() {
    int n;
    cin>>n;
    vector<char> temp;
    for (int i = 0; i < n; i++){
        char t;
        cin>>t;
        temp.push_back(t);
    }
    
    vector<vector<char>> res;

    res = permute(temp);
    // cout<<"out\n";
    for (auto i : res) {
        for (auto ii : i) {
        cout << ii << " ";
        }
    cout << "\n";
    }
    return 0;
}