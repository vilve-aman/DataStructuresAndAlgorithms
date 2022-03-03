#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

int eggDrop(int eggs, int floors){
    // base case 
    if(eggs==1){
        dp[eggs][floors]=floors;
        return floors;
    }
    if(floors==1 || floors ==0){
        dp[eggs][floors]=floors;
        return floors;
    }

    if(dp[eggs][floors]!=-1){
        return dp[eggs][floors];
    }
    // recursive case 
    int minAttempts=INT_MAX;    
    int low,high;
    for (int k = 1; k <= floors; k++){
        // -------------------------------------------------------------------to find in lower part of building incase egg breaks/////////////////////////////////////
        if(dp[eggs-1][k-1]!=-1)     low=dp[eggs-1][k-1] ;
        else                                        low=eggDrop(eggs-1,k-1);
        // -------------------------------------------------------------------to find in lupperpart of building incase egg does nor breaks/////////////////////////////////////
        if(dp[eggs][floors-k]!=-1)     high=dp[eggs][floors-k] ;
        else                                             high=eggDrop(eggs,floors-k);

        int tempAns=1+max( low , high );
        minAttempts=min( minAttempts , tempAns);
    }
    dp[eggs][floors]=minAttempts;
    return minAttempts;

}

int main(){
    cout<<"hello world.😉\n";
    int eggs,floors;
    cin>>eggs>>floors;
    memset(dp, -1, sizeof(dp));
    cout<<eggDrop(eggs,floors);
    return  0;
}


// // inp uts
// 3 10
// // outputs 
// hello world.😉
// 4
