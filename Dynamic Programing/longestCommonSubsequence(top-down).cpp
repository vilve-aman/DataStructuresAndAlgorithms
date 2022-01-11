#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string x,string y, int n, int m, vector<vector<int>> &dp){
    // base case 
    for (int i = 0; i < n+1; i++)    {
        for (int j = 0; j < m+1 ; j++)        {
            if (i==0 || j==0){
                dp[i][j]=0;
            }            
        }        
    }

    // recursive case 
    for (int i = 1; i < n+1; i++)    {
        for (int j = 1; j < m+1 ; j++)        {
            if (x[i-1]==y[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }       
            else{
                dp[i][j] = max( dp[i][j-1] , dp[i-1][j] );
            }     
        }        
    }
    

}

int main(){
    cout<<"hello world.😉\n";
    string x,y;
    cin>>x>>y;

    vector<vector<int>> dp(x.length()+1, vector<int> (y.length()+1, -1) );
    longestCommonSubsequence(x,y,x.length(), y.length(), dp);

    cout<<dp[x.length()][y.length()];

    return  0;

}