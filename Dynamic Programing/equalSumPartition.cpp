#include <bits/stdc++.h>
using namespace std;

void knapSack(int n, int limit, int weights[],  vector<vector<bool>> &dp ){
    // initialisation 
    for (int i = 0; i < n+1 ; i++){
        for (int j = 0; j < limit+1 ; j++){
            if (i==0){
                dp[i][j]=false;
            }
            if (j==0){
                dp[i][j]=true;
            }

        }        
    }

    for (int i = 1; i < n+1 ; i++){
        for (int j = 1; j < limit+1 ; j++){
            if (weights[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]= ( dp[i-1][j-weights[i-1]] || dp[i-1][j] );
            }
            
        }
    }


}

int main(){
    cout<<"hello world.😉\n";

    int n,limit,range=0;
    cin>>n;
    int weights[n];
    for (int i = 0; i < n; i++){
        cin>>weights[i];
        range+=weights[i];
    }

    if (range%2==0){
        limit=range/2;
        vector<vector<bool>> dp(n+1, vector<bool> ( limit+1, false));
        knapSack(n,limit, weights, dp);
        cout<<dp[n][limit];

    }
    else{
        cout<<false;
    }

    
    
    return  0;
}