#include <bits/stdc++.h>
using namespace std;


void printvector(vector<int> &v){
    for (int i = 0; i < v.size() ; i++){
        if (v[i]==0){
            cout<<v[i]<<"  ";
        }
        else
            cout<<v[i]<<" ";        
    }
    
}

void knapSack(int limit, int n, int  weights[], int  values[], vector<vector<int>> &dp){
cout<<"hello";

    for (int i = 1; i < n+1 ; i++){
        for (int j = 1; j < limit+1 ; j++){

            if (weights[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max( values[i-1]+dp[i-1][j-weights[i-1]] , dp[i-1][j] );
            }
            
        }
        
    }
    
}

int main(){
    cout<<"hello world.😉\n";

    int n,limit;
    cin>>n>>limit;
    
    int weights[n], values[n];
    vector<vector<int>> dp(n+1, vector<int> (limit+1, -1));

    for (int i = 0; i < n; i++){
        cin>>weights[i];
    }

    for (int i = 0; i < n; i++){
        cin>>values[i];
    }
    // initialization of dp 
    for (int i = 0; i < n+1; i++){
        for (int j = 0; j < limit+1; j++){
            if (i==0 || j==0){
                dp[i][j]=0;
            }            
        }        
    }


    knapSack(limit, n, weights,values,dp);
    cout<<dp[n][limit]<<"\n";

    for(auto i : dp){
        printvector(i);
        cout<<endl;
    }

    return  0;
}




// tested inputs 

// 4 10
// 1 3 4 6
// 20 30 10 50
// output 
// 100