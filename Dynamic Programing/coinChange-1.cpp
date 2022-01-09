// coinChange -1 maximum no of ways to form a number  from given coins ------------ classic variation of unbounded knapsack

#include <bits/stdc++.h>
using namespace std;

void printvector(vector<int> &v){
    for (int i = 0; i < v.size() ; i++)
        cout<<v[i]<<" ";         
}

void coinChange(int n, int limit, int coins[], vector<vector<int>> &dp ){
// base case
    for (int i = 0; i < n+1; i++){
        for (int j = 0; j < limit+1 ; j++)    {
            if (i==0)        {
                dp[i][j]=0;
            }
            if (j==0)        {
                dp[i][j]=1;
            }
        }    
    }
// recursive case 
    for (int i = 1; i < n+1; i++){
        for (int j = 1; j < limit+1 ; j++)    {
            if (coins[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
            }
        }    
    }
    return ;
}

int main(){

    int n,limit;
    cin>>n>>limit;
    int arr[n];
    for (int i = 0; i < n; i++)    {
        cin>>arr[i];
    }

    vector<vector<int>> dp(n+1, vector<int> (limit+1, -1 ));

    coinChange(n, limit, arr, dp );
        
    for(auto i : dp){
        printvector(i);
        cout<<endl;
    }
        cout<<"hello world.😉\t "<<dp[n][limit];
    return  0;
}

// inputs tested 
// 3 5
// 1 2 3

// output
// 1 0 0 0 0 0 
// 1 1 1 1 1 1 
// 1 1 2 2 3 3 
// 1 1 2 3 4 5 
// hello world.😉	 5
