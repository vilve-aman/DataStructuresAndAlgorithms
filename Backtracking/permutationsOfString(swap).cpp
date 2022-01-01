#include "bits/stdc++.h"
using namespace std;

void solve(vector<char> &nums, vector<vector<char>> &ans, int idx) {
    // cout<<idx<<" ";
    if (idx == nums.size()) {
    ans.push_back(nums);
    return ;
    }
    for (int i = idx; i < nums.size(); i++) {
    swap(nums[i], nums[idx]);
    solve(nums, ans, idx + 1);
    swap(nums[i], nums[idx]);
    }
}
vector<vector<char>> permute(vector<char> nums) {
    vector<vector<char>> ans;
    solve(nums,ans,0);
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