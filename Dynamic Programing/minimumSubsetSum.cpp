#include <bits/stdc++.h>
using namespace std;

void printvector(vector<bool> &v){
    for (int i = 0; i < v.size() ; i++)
        cout<<v[i]<<" ";         
}


void subsetSum(int n, int limit, int arr[], vector<vector<bool>> &dp){
    // base case  -------- initialisatoin 
    for (int i = 0; i < n+1; i++)    {
        for (int j = 0; j < limit+1; j++)        {
            if(i==0)
                dp[i][j]=false;
            if(j==0)
                dp[i][j]=true;
        }
        
    }

    // recursive case ------normal case 
    for (int i = 1; i < n+1; i++)    {
        for (int j = 1; j < limit+1; j++)        {
            if(arr[i-1]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=( dp[i-1][j-arr[i-1]] || dp[i-1][j ]);
        }
        
    }

    return;
}

int main(){
    cout<<"hello world.😉\n";

    int n;
    cin>>n;
    int arr[n],range=0;
    for (int i = 0; i < n; i++){
        cin>>arr[i];
        range+=arr[i];
    }

    int limit=range/2;
    vector<vector<bool>> dp(n+1,vector<bool> (limit+1,false));

    subsetSum(n, limit, arr, dp );
    
    for(auto i : dp){
        printvector(i);
        cout<<endl;
    }

    int min=INT_MAX;

    for (int j = 1; j < limit+1; j++)    {
        if ( dp[n][j] )        {
            if(range-(2*j) < min)   min=range-(2*j);
        }
        
    }
    
    cout<<"\nminimum possible difference is "<<min;
    
    return  0;
}