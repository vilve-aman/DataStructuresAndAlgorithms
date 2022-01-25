#include <bits/stdc++.h>
using namespace std;

bool isSafe(int** arr, int &n, int sr, int sc){
    if(sr<n && sc<n && sr>=0 && sc>=0 && arr[sr][sc]==0){
        return true;
    }
    return false;
}


bool knightTour(int** arr, int &n, int sr, int sc, int move){
    // cout<<move<<endl;
    if(move>n*n){
        return true;
    }

    if(isSafe(arr,n,sr,sc)){
        arr[sr][sc]=move;
        move++;
        if(knightTour(arr,n,sr-2,sc+1,move)){
            return true;
        }
        if(knightTour(arr,n,sr-1,sc+2,move)){
            return true;
        }
        if(knightTour(arr,n,sr+1,sc+2,move)){
            return true;
        }
        if(knightTour(arr,n,sr+2,sc+1,move)){
            return true;
        }
        // ----------------------------------------------------------------------------------------------
        if(knightTour(arr,n,sr+2,sc-1,move)){
            return true;
        }
        if(knightTour(arr,n,sr+1,sc-2,move)){
            return true;
        }
        if(knightTour(arr,n,sr-1,sc-2,move)){
            return true;
        }
        if(knightTour(arr,n,sr-2,sc-1,move)){
            return true;
        }

        arr[sr][sc]=0;
        move --;
        return false;
    }
    return false;

}

int main(){
    cout<<"hello world.😉\n";
    int n;
    cin>>n;
    int r, c;
    cin>>r>>c;

    int** arr = new int*[n];

    for (int i = 0; i < n; i++)    {
        arr[i]=new int[n];
        for (int j = 0; j < n; j++)        {
            arr[i][j]=0;
            // cout<<arr[i][j]<<" ";
        }
        // cout<<endl;        
    }

    cout<<knightTour(arr,n,r,c,1)<<endl;

    for (int  i = 0; i < n; i++)    {
        for (int j = 0; j < n; j++)        {
           if(arr[i][j]/10==0)      cout<<arr[i][j]<<"  ";
           else     cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    

    
    return  0;
}


// inputs tested 
// 5
// 2 2

// hello world.😉
// 1
// 21 12 7  2  19 
// 6  17 20 13 8  
// 11 22 1  18 3  
// 16 5  24 9  14 
// 23 10 15 4  25