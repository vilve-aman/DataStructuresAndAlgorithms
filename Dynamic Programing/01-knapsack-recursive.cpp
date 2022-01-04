#include <bits/stdc++.h>
using namespace std;

int knapSack(int limit, int n, int  weights[], int  values[]){
    // cout<<limit<<" ";
    // base condition 
    if (limit==0 || n<0){
        return 0;
    }

    // recursive case 
    if (limit<weights[n-1]){
        return  knapSack(limit, n-1, weights, values);
    }
    else{
        return  max( values[n-1]+knapSack(limit-weights[n-1], n-1, weights, values), knapSack(limit, n-1, weights, values) );
    }
    
    
}

int main(){
    cout<<"hello world.😉\n";

    int n,limit;
    cin>>n>>limit;
    
    int weights[n], values[n];


    for (int i = 0; i < n; i++){
        cin>>weights[i];
    }

    for (int i = 0; i < n; i++){
        cin>>values[i];
    }


    cout<<knapSack(limit, n, weights,values);
    

    return  0;
}