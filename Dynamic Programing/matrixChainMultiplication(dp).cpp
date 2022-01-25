#include <bits/stdc++.h>
using namespace std;

int mcm (vector<int> v, int i, int j, vector<vector<int>> &dp){
// base case 
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
// recursive case 
    int ans= INT_MAX;
    for (int k = i; k < j; k++)    {
        int tempans = mcm(v,i,k,dp) + mcm(v,k+1,j,dp) + v[i-1]*v[k]*v[j] ;
        if(tempans<ans) ans=tempans;
    }
    dp[i][j]=ans;
    return ans;
}

int main(){
    cout<<"hello world.😉\n";
    int n;
    cin>>n;
    vector<int> v(n,0);
    vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
    for (int i = 0; i < n; i++)    {
        cin>>v[i];
    }
   
    cout<<mcm(v,1,n-1,dp);

    // for(auto i : dp){
    //     for(auto j: i) cout<<j<<" ";
    //     cout<<endl;
    // }
    return  0;
}


// inputs  tested
// 5
// 40 20 30 10 30
// output 
// hello world.😉
// 26000