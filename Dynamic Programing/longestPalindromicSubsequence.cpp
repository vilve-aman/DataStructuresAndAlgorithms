#include <bits/stdc++.h>
using namespace std;

void lps(string a, string b, int n ){
    vector<vector<int>> dp(n+1, vector<int> (n+1, -1));

    // base condition 
    for (int i = 0; i < n+1; i++)    {
        for (int j = 0; j < n+1 ; j++)        {
            if (i==0 || j==0){
                dp[i][j]=0 ;
            }
        }        
    }

    // recursive case 
    for (int i = 1; i < n+1; i++)    {
        for (int j = 1; j < n+1 ; j++)        {
            if (a[i-1]==b[j-1] ){
                dp[i][j]=dp[i-1][j-1] + 1 ;
            }
            else{
                dp[i][j]=max( dp[i][j-1] , dp[i-1][j]);
            }
        }        
    }

    cout<<"lps : "<<dp[n][n]; 
}

int main(){
    cout<<"hello world.😉\n";
    string a,b;
    cin>>a;
    b=a;
    reverse(b.begin() , b.end());
    cout<<b<<endl;
    lps(a, b, a.length() );
    return  0;
}


// inputs tested
// pappu
// hello world.😉
// uppap
// lps : 3

// agbcba
// hello world.😉
// abcbga
// lps : 5


// one of the application of longest palindromic subsequence is --- (  minimun number of deletiond to make a string palindromic )
// solution :  length of string - lps()