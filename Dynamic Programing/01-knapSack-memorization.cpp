#include <bits/stdc++.h>
using namespace std;

int knapSack(int limit, int n, int  weights[], int  values[], vector<vector<int>> &solution){
    
    // base condition 
    if (limit==0 || n<0){
        return 0;
    }

    // recursive case 
    if (limit<weights[n-1]){
        if (solution[n][limit]!=-1)     return solution[n][limit];
        else       solution[n][limit]=knapSack(limit, n-1, weights, values, solution);
        return  solution[n][limit];
    }
    else{
        if (solution[n][limit]!=-1)     return solution[n][limit];
        else       solution[n][limit]=max(values[n-1]+knapSack(limit-weights[n-1], n-1, weights, values, solution), knapSack(limit, n-1, weights, values, solution));
        return  solution[n][limit];
    }
    
    
}

int main(){
    cout<<"hello world.😉\n";

    int n,limit;
    cin>>n>>limit;
    
    int weights[n], values[n];
    vector<vector<int>> solution(n+1, vector<int> (limit+1, -1));

    for (int i = 0; i < n; i++){
        cin>>weights[i];
    }

    for (int i = 0; i < n; i++){
        cin>>values[i];
    }


    cout<<knapSack(limit, n, weights,values, solution);
    

    return  0;
}




// tested inputs 

// 4 10
// 1 3 4 6
// 20 30 10 50
// output 
// 10