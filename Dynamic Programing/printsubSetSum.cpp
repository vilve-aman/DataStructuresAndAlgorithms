#include <bits/stdc++.h>
using namespace std;

void printdp(vector<vector<int>> &dp,  vector<int> &weights , int i){
    int j = dp[0].size()-1;
    while(j>0 && i>0){
            
            if(dp[i-1][j]==1){
                if(dp[i-1][j-weights[i-1]] == 1){
                    cout<<weights[i-1]<<"  ";
                    j=j-weights[i-1];
                    i--;
                }
            }
            else if(dp[i-1][j-weights[i-1]] == 1){
                cout<<weights[i-1]<<"  ";
                j=j-weights[i-1];
                i--;
            }

    }

}

void printSubset(vector<vector<int>> &dp, int limit, vector<int> &weights){
    for (int i = 1; i < dp.size(); i++){
        if(dp[i][limit]==1){
            printdp(dp,weights,i);   
            cout<<endl;         
        }
    }
    
}

void subsetSum(int n, int limit, vector<int> &weights){
    vector<vector<int>> dp(n+1, vector<int> (limit+1, -1));
    // base case 
    for (int i = 0; i < n+1; i++)    {
        for (int j = 0; j < limit+1; j++)        {
            if(i==0) dp[i][j]=0;
            if(j==0) dp[i][j]=1;
        }
        
    }
    
    // recursive case 
    for (int i = 1; i < n+1; i++)    {
        for (int j = 1; j < limit+1; j++)        {
            if(weights[i-1] > j ) dp[i][j]=dp[i-1][j];
            else{
                dp[i][j] = max(dp[i-1][ j-weights[i-1] ] , dp[i-1][j] );
            }
        }
        
    }

    for(auto i: dp){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    printSubset(dp,limit,weights);
    // cout<<dp[n][limit];
}
int main(){
    cout<<"hello world.😉\n";
    int n,limit;
    cin>>n>>limit;
    vector<int> weights(n,0);
    for (int i = 0; i < n; i++)    {
        cin>>weights[i];
    }

    subsetSum(n,limit,weights);
    
    return  0;
}


// // inputs 
// 5 5
// 5 7 4 3 1 

// // outputs 
// hello world.😉
// 5 
// 1 3 not possible with this case