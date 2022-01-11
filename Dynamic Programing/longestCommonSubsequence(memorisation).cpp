#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string x, string y, int n,  int m, vector<vector<int>> &dp){
    if(dp[n][m]!=-1){
        return dp[n][m];
    }

    // base condition 
    if (n==0 || m==0 ){
        return 0;
    }

    // recursive case 
    if( x[n-1] == y[m-1] ){
        dp[n][m] = 1 + longestCommonSubsequence(x,y,n-1,m-1, dp);
        return dp[n][m];
    }
    else{
        dp[n][m] = max( longestCommonSubsequence(x,y,n-1,m, dp) , longestCommonSubsequence(x,y,n,m-1, dp) );
        return dp[n][m];
    }

}

int main(){
    cout<<"hello world.😉\n";
    string x,y;
    cin>>x>>y;

    vector<vector<int>> v(x.length()+1,vector<int> (y.length()+1, -1));

    cout<<longestCommonSubsequence(x,y,x.length(),y.length(),v);

    return  0;
}