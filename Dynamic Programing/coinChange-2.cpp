// Coin Change 2 - minimum number of coins required to make a limit -- by aditya verma
// this is clasical problem of greedy known as indian coin change 

#include <bits/stdc++.h>

using namespace std;

void printvector(vector<long long int> &v){
    for (int i = 0; i < v.size() ; i++){
        if (v[i] ==  INT_MAX-1 ) cout<<"IM"<<"  ";
        else    cout<<v[i]<<"   ";    
    }       
}

void coinChange(int n, int limit, int coins[], vector<vector<long long int>> &dp ){
// base case
    for (int i = 0; i < n+1; i++){
        for (int j = 0; j < limit+1 ; j++)    {
            if (j==0)        {
                dp[i][j]=0;
            }
            if (i==0)        {
                dp[i][j]=INT_MAX-1;
            }
        }    
    }
// recursive case 
    for (int i = 1; i < n+1; i++){
        for (int j = 1; j < limit+1 ; j++)    {
            if (coins[i-1]>j ){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j] = min( 1+dp[i][j-coins[i-1]] , dp[i-1][j] );
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

    vector<vector<long long int>> dp(n+1, vector<long long int> (limit+1, -1 ));

    coinChange(n, limit, arr, dp );
        
    for(auto i : dp){
        printvector(i);
        cout<<endl;
    }
        cout<<"hello world.😉\t "<<dp[n][limit];
    return  0;
}

// inputs tested 

// 2 7
// 5 2
// output 
// IM  IM  IM  IM  IM  IM  IM  IM  
// 0   IM  IM  IM  IM  1   IM  IM  
// 0   IM  1   IM  2   1   3   2   
// hello world.😉	 2


// 3 4
// 1 3 5
// output 
// IM  IM  IM  IM  IM  
// 0   1   2   3   4   
// 0   1   2   1   2   
// 0   1   2   1   2   
// hello world.😉	 2
