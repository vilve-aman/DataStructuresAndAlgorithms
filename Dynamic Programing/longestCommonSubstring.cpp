#include <bits/stdc++.h>
using namespace std;

void printvector(vector<int> &v){
    for (int i = 0; i < v.size() ; i++){
        if (v[i] ==  INT_MAX-1 ) cout<<"IM"<<"  ";
        else    cout<<v[i]<<"   ";    
    }       
}

int longestCommonSubsequence(string x,string y, int n, int m, vector<vector<int>> &dp){
    int max=0;
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
                dp[i][j] =0;
            }  
            if(dp[i][j]>max)    max=dp[i][j];   
        }         
    }
    return max;

}

int main(){
    cout<<"hello world.😉\n";
    string x,y;
    cin>>x>>y;

    vector<vector<int>> dp(x.length()+1, vector<int> (y.length()+1, -1) );
    cout<<longestCommonSubsequence(x,y,x.length(), y.length(), dp)<<endl;

    for(auto i : dp){
        printvector(i);
        cout<<endl;
    }

    

    return  0;

}


// inputs tested 
// abcdef
// acdfhi
// output 
// hello world.😉
// 2
// 0   0   0   0   0   0   0   
// 0   1   0   0   0   0   0   
// 0   0   0   0   0   0   0   
// 0   0   1   0   0   0   0   
// 0   0   0   2   0   0   0   
// 0   0   0   0   0   0   0   
// 0   0   0   0   1   0   0


// inputs tested 
// abdef
// xabdy
// output 
// hello world.😉
// 3
// 0   0   0   0   0   0   
// 0   0   1   0   0   0   
// 0   0   0   2   0   0   
// 0   0   0   0   3   0   
// 0   0   0   0   0   0   
// 0   0   0   0   0   0
