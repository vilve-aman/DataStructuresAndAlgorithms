#include <bits/stdc++.h>
using namespace std;

void printvector(vector<int> &v){
    for (int i = 0; i < v.size() ; i++)
        cout<<v[i]<<" ";         
}


void subsetSum(int n, int limit, int arr[], vector<vector<int>> &dp){
    // base case  -------- initialisatoin 
    for (int i = 0; i < n+1; i++)    {
        for (int j = 0; j < limit+1; j++)        {
            if(i==0)
                dp[i][j]=0;
            if(j==0)
                dp[i][j]=1;
        }
        
    }

    // recursive case ------normal case 
    for (int i = 1; i < n+1; i++)    {
        for (int j = 1; j < limit+1; j++)        {
            if(arr[i-1]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=( dp[i-1][j-arr[i-1]] + dp[i-1][j ]);
        }
        
    }

    return;
}

int main(){
    cout<<"hello world.😉\n";

    int n,diff;
    cin>>n>>diff;
    int arr[n],range=0;
    for (int i = 0; i < n; i++){
        cin>>arr[i];
        range+=arr[i];
    }

    int limit=(range+diff)/2;
    vector<vector<int>> dp(n+1,vector<int> (limit+1,-1));

    subsetSum(n, limit, arr, dp );
    
    for(auto i : dp){
        printvector(i);
        cout<<endl;
    }

    if(dp[n][limit] != -1)
    cout<<"\nminimum possible difference is "<<dp[n][limit];
    
    return  0;
}