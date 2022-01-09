#include <bits/stdc++.h>
using namespace std;

void printvector(vector<int> &v){
    for (int i = 0; i < v.size() ; i++)
        cout<<v[i]<<" ";         
}

void unboundedKnapsack(int n, int limit, int arr[], int val[], vector<vector<int>> &dp){
    // base case 
    for (int i = 0; i < n+1 ; i++){
        for (int j = 0; j < limit+1 ; j++){
            if (i==0 || j==0 ) dp[i][j]=0;
        }
        
    }

    // recursive case 
    for (int i = 1; i < n+1 ; i++){
        for (int j = 1; j < limit+1 ; j++){
            if (arr[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]= max( val[i-1]+dp[i][j-arr[i-1]] , dp[i-1][j] );
            }
        }  
    }

    return ;
}

int main(){
    cout<<"hello world.😉\n";
    int n,limit ;
    cin>>n>>limit;
    int arr[n],val[n];
    for (int i = 0; i < n; i++)    {
        cin>>arr[i];
    }
    for (int i = 0; i < n; i++)    {
        cin>>val[i];
    }

    vector<vector<int>> dp(n+1,vector<int> (limit+1, -1));
    
    unboundedKnapsack(n,limit,arr,val,dp);

    for(auto i : dp){
        printvector(i);
        cout<<endl;
    }
    return  0;
}


// inputs tested 
// 5 7
// 2 5 1 3 4
// 15 14 10 45 30

// output_
// 0 0 0 0 0 0 0 0 
// 0 0 15 15 30 30 45 45 
// 0 0 15 15 30 30 45 45 
// 0 10 20 30 40 50 60 70 
// 0 10 20 45 55 65 90 100 
// 0 10 20 45 55 65 90 100