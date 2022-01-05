#include <bits/stdc++.h>
using namespace std;


void printvector(vector<int> &v){
    for (int i = 0; i < v.size() ; i++)
        cout<<v[i]<<" ";         
}

void knapSack(int limit, int n, int  weights[], vector<vector<int>> &dp){

    // initialization of dp         --bsae  condition in recurcive solution
    for (int i = 0; i < n+1; i++){
        for (int j = 0; j < limit+1; j++){
            if ( i==0){
                dp[i][j]=0;
            }       
            if ( j==0){
                dp[i][j]=1;
            }      
        }        
    }


    for (int i = 1; i < n+1 ; i++){
        for (int j = 1; j < limit+1 ; j++){

            if (weights[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]= dp[i-1][j-weights[i-1]] + dp[i-1][j] ;
            }
            
        }
        
    }
    
}

int main(){
    cout<<"hello world.😉\n";

    int n,limit;
    cin>>n>>limit;
    
    int weights[n];
    vector<vector<int>> dp(n+1, vector<int> (limit+1, 0));

    for (int i = 0; i < n; i++){
        cin>>weights[i];
    }

  for(auto i : dp){
        printvector(i);
        cout<<endl;
    }

    knapSack(limit, n, weights, dp);

    cout<<dp[n][limit]<<"\n";

    for(auto i : dp){
        printvector(i);
        cout<<endl;
    }

    return  0;
}
